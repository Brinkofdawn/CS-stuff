#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HEIGHT 25 // board height
#define WIDTH 25// board width
#define TEAMSIZE 9 // team size
#define TURNS  1000 // maximum number of turns




enum {team1, team2, empty, border}; // (0,1,2,3)
enum {none, north, south, east, west,bordered}; // (0,1,2,3,4)

typedef struct piecedata piecedata;
struct piecedata // holds all the information about each board square
{
    int type; // what type of square
    int direction; // the direction the piece is currently going
    int id; // the piece id 
    int moved; // whether or not the player has moved this turn
};


char pieces[]= "12-#";       // Characters to represent pieces
char directions[]= "-NSEW#";       // Characters to represent pieces
struct piecedata board[HEIGHT+2][WIDTH+2]; //Declare board size. With Borders

// Prototypes

void initboard(); // initialize board with empty squares
void printboard();// printing the board
void initplayers(); // put the players randomly in the array
void nextturn(); // function containing turn logic
void resetmoved(); // resets all the players to have not moved that turn
void printdirection(); // prints the current direction of all the pieces
int checkwin(); // checks the win state of the board
int countleft(); // in case of tie counts the number of players left on each team
int main(){
//Initialize Variables
srand(time(NULL));
//initialize board and players
initboard();
initplayers();
//print initial board
 printf("\n Current Position\n");
printboard();
//print initial direction of pieces
 printf("\n Table of Directions \n");
printdirection();
 printf("\n"); // print newline for spacing

//take number of turns up to specified amount
for (int i = 0; i < TURNS; i++){
    nextturn(0,TEAMSIZE*2);

    if (i % 10 == 0){ // print the current board every 10 rounds
         printf("\n Current Position\n");
        printboard(); 
        printf("\n Table of Directions \n");
        printdirection();
    printf("\n \n");// newline to space out board
}




    if(checkwin()== 20){ // cheking if Team 2 has won the game
        printf("Final Board \n");
        printboard();
         printf("Team B has won at turn %d \n", i);
        i= i +TURNS;}

    else if(checkwin()== 10){ // checking if Team 1 has won the game
        printf("Final Board \n");
        printboard();
        printf("Team A has won at turn %d \n", i);
        i= i +TURNS;
}

else if (TURNS-i == 1){ // if all rounds have gone by and there is no winning team
        printf("Final Board \n");
        printboard();
        printf("After all %d rounds there is a tie! \n", TURNS);
        printf("%d player(s) on Team A survived \n", countleft(team1));
         printf("%d player(s) on Team B survived \n",countleft(team2));

    }
resetmoved();
}



    
}//end main
void resetmoved(){
      int rows;
    int columns;
for ( columns = 1; columns < HEIGHT +1;  columns++ )
    {
        //Create the columns for the board
        for (rows = 1; rows < WIDTH+1; rows++ )
         { 
           
            board[columns][rows].moved= 0;
  

    }
  }

}
int wincondition1(){ // checking if there are any Team1 players left on the board
     int rows;
    int columns;
for ( columns = 1; columns < HEIGHT +1;  columns++ )
    {
        //Create the columns for the board
        for (rows = 1; rows < WIDTH+1; rows++ )
         { 
           
          if (board[columns][rows].type== team1){
            return 1;
          }

    }
  }
    return 0;
}


int wincondition2(){ // checking if there are any Team2 players left on the board
     int rows;
    int columns;
for ( columns = 1; columns < HEIGHT +1;  columns++ )
    {
        //Create the columns for the board
        for (rows = 1; rows < WIDTH+1; rows++ )
         { 
           
          if (board[columns][rows].type== team2){
            return 1;
          }

    }
  }
    return 0;
}

int checkwin(){ // checking to see if any win conditions have been met

if (wincondition1()==0){
return 20;
}

else if (wincondition2()==0){
return 10;
}

else{
    return 1;
}

}


void initboard(){
    int rows;
    int columns;
    for ( columns = 0; columns < HEIGHT +2;  columns++ )
    {
        //Create the borders
        for (rows = 0; rows < WIDTH+2; rows++ )
         { 
         board[columns][rows].type=border;
         board[columns][rows].direction=bordered;
         board[columns][rows].id= 0;


    }
  }
      for ( columns = 1; columns < HEIGHT +1;  columns++ )
    {
        //Create the empty spaces
        for (rows = 1; rows < WIDTH+1; rows++ )
         { 
            board[columns][rows].type=empty;
            board[columns][rows].direction=none;
            board[columns][rows].id= 0;
            board[columns][rows].moved= 0;
  

    }
  }
}

void randomspot(int i, int teamnumber){
int randheight= 1+(rand() % HEIGHT-1);
int randwidth= 1+(rand() % WIDTH-1);
int randdirection= 1+(rand() % 4);
if (board[randheight][randwidth].type==empty){ // checking if spot is empty
    board[randheight][randwidth].type= teamnumber;
     board[randheight][randwidth].direction= randdirection;
    board[randheight][randwidth].id= i;

}
else{  // if not empty try another spot
    randomspot(i, teamnumber);
}

}



void initplayers(){

for (int i = 0; i < TEAMSIZE; i++) 
{randomspot(i, team1);}// initializing players with unique ids
for (int i = TEAMSIZE; i < TEAMSIZE*2; i++)
{randomspot(i,team2);}
}

int countleft(int teamnumber){
   int count; // current count of left
   count=0;
    for (int columns = 1; columns < HEIGHT +1;  columns++ )
    {
        for (int rows = 1; rows < WIDTH+1; rows++ )
         { 
           if (board[columns][rows].type== teamnumber){
                count++;
          }
  

    }
  }
  return count;
}

void nextturn(int start, int players){
 
     for (int columns = 1; columns < HEIGHT +1;  columns++ )
    {
        //Sacnning each individual row that is not a border for pieces
        for (int rows = 1; rows < WIDTH+1; rows++ )
         { 
            
                
            
            if((board[columns][rows].type==team1 ||board[columns][rows].type==team2)&& board[columns][rows].moved==0 ){
                // For heading North
                if (board[columns][rows].direction==south){
                    // if space ahead is empty
                    if (board[columns+1][rows].type==empty){
                        board[columns+1][rows].type=board[columns][rows].type;
                        board[columns+1][rows].direction=board[columns][rows].direction;
                        board[columns+1][rows].id=board[columns][rows].id;
                        board[columns+1][rows].moved=1;
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;

                    }
                    else if (board[columns+1][rows].type==border){ // if border tehn take turn to swap directions
                        board[columns][rows].direction=north;
                                nextturn(board[columns][rows].id,board[columns][rows].id+1);
                    
                    }
                    // jumping over a teammate if there is no border 2 spaces ahead
                    else if (board[columns+1][rows].type==board[columns][rows].type && board[columns+2][rows].type != border){
                        board[columns+2][rows].type=board[columns][rows].type;
                        board[columns+2][rows].direction=board[columns][rows].direction;
                        board[columns+2][rows].id=board[columns][rows].id;                        
                        board[columns+2][rows].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;
                    }
                    // if other team or there is teammate ahead with a border 2 spaces ahead
                    else{
                        board[columns+1][rows].type=board[columns][rows].type;
                        board[columns+1][rows].direction=board[columns][rows].direction;
                        board[columns+1][rows].id=board[columns][rows].id;
                        board[columns+1][rows].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;
                    }
             
                }


                // For heading South
                else if (board[columns][rows].direction==north){
                    // if space ahead is empty
                    if (board[columns-1][rows].type==empty){
                        board[columns-1][rows].type=board[columns][rows].type;
                        board[columns-1][rows].direction=board[columns][rows].direction;
                        board[columns-1][rows].id=board[columns][rows].id;
                        board[columns-1][rows].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;

                    }
                    else if (board[columns-1][rows].type==border){ // if border tehn take turn to swap directions
                        (board[columns][rows].direction=south);
                                nextturn(board[columns][rows].id,board[columns][rows].id+1);

                    }
                    // jumping over a teammate if there is no border 2 spaces ahead
                    else if (board[columns-1][rows].type==board[columns][rows].type && board[columns-2][rows].type != border){
                        board[columns-2][rows].type=board[columns][rows].type;
                        board[columns-2][rows].direction=board[columns][rows].direction;
                        board[columns-2][rows].id=board[columns][rows].id;
                        board[columns-2][rows].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;
                    }
                    // if other team or there is teammate ahead with a border 2 spaces ahead
                    else{
                        board[columns-1][rows].type=board[columns][rows].type;
                        board[columns-1][rows].direction=board[columns][rows].direction;
                        board[columns-1][rows].id=board[columns][rows].id;
                        board[columns-1][rows].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;
                    }
    
                }


                    // For heading East
              else if (board[columns][rows].direction==east){
                    // if space ahead is empty
                    if (board[columns][rows+1].type==empty){
                        board[columns][rows+1].type=board[columns][rows].type;
                        board[columns][rows+1].direction=board[columns][rows].direction;
                        board[columns][rows+1].id=board[columns][rows].id;
                        board[columns][rows+1].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;

                    }
                    else if (board[columns][rows+1].type==border){ // if border tehn take turn to swap directions
                        (board[columns][rows].direction=west);
                                nextturn(board[columns][rows].id,board[columns][rows].id+1);

                    }
                    // jumping over a teammate if there is no border 2 spaces ahead
                    else if (board[columns][rows+1].type==board[columns][rows].type && board[columns][rows+2].type != border){
                        board[columns][rows+2].type=board[columns][rows].type;
                        board[columns][rows+2].direction=board[columns][rows].direction;
                        board[columns][rows+2].id=board[columns][rows].id;
                        board[columns][rows+2].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;
                    }
                    // if other team or there is teammate ahead with a border 2 spaces ahead
                    else{
                        board[columns][rows+1].type=board[columns][rows].type;
                        board[columns][rows+1].direction=board[columns][rows].direction;
                        board[columns][rows+1].id=board[columns][rows].id;
                        board[columns][rows+1].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;
                    }
 
                }

                   // For heading West
            else if (board[columns][rows].direction==west){
                    // if space ahead is empty
                    if (board[columns][rows-1].type==empty){
                        board[columns][rows-1].type=board[columns][rows].type;
                        board[columns][rows-1].direction=board[columns][rows].direction;
                        board[columns][rows-1].id=board[columns][rows].id;
                        board[columns][rows-1].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;

                    }
                    else if (board[columns][rows-1].type==border){ // if border tehn take turn to swap directions
                        (board[columns][rows].direction=east);
                                nextturn(board[columns][rows].id,board[columns][rows].id+1);

                    }
                    // jumping over a teammate if there is no border 2 spaces ahead
                    else if (board[columns][rows-1].type==board[columns][rows].type && board[columns][rows-2].type != border){
                        board[columns][rows-2].type=board[columns][rows].type;
                        board[columns][rows-2].direction=board[columns][rows].direction;
                        board[columns][rows-2].id=board[columns][rows].id;
                        board[columns][rows-2].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;
                    }
                    // if other team or there is teammate ahead with a border 2 spaces ahead
                    else{
                        board[columns][rows-1].type=board[columns][rows].type;
                        board[columns][rows-1].direction=board[columns][rows].direction;
                        board[columns][rows-1].id=board[columns][rows].id;
                        board[columns][rows-1].moved=1;       
                        board[columns][rows].type=empty;
                        board[columns][rows].direction=none;
                        board[columns][rows].id=0;
                    }
                }

            }
        
  

    }
  }
}





void printboard(){
    int rows;
    int columns;
      for ( columns = 0; columns < HEIGHT +2;  columns++ )
    {
        for (rows = 0; rows < WIDTH+2; rows++ )
         { 
    if (board[columns][rows].type==border || board[columns][rows].type==empty){
    printf("%3c", pieces[board[columns][rows].type]); // print the symbols for border and empty spaces
    }
    else if(board[columns][rows].type==team1){
        printf(" A%d",board[columns][rows].id);
    }
    else{
        printf(" B%d",board[columns][rows].id-TEAMSIZE);
    }

    }
     printf("\n");
  }
}
void printdirection(){
    int rows;
    int columns;
      for ( columns = 0; columns < HEIGHT +2;  columns++ )
    {
        //Create the columns for the board
        for (rows = 0; rows < WIDTH+2; rows++ )
         { 

    printf("%3c", directions[board[columns][rows].direction]);

    }
     printf("\n");
  }
}

