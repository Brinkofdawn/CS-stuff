#include "Board.h"
#include <cstdio>
#include <cstdlib> 


//Arun Donti whole file

Board::Board(Receiver *R, Source *S, Mules *M) // holds the class to print out the board
{
	this->R=R;
	this->S=S;
	this->M=M;
}
void Board::makeBoard(int Size){ // initialize the board
	int S = Size;
	int board[S][S];
	for (int i = 0; i<Size; i++){
		for(int j= 0; j<Size; j++){
			board[i][j] = 0;
		}
	}
	Receiver* Re = new Receiver();
	Source* So = new Source();
	Mules* Mu = new Mules();
	Re = this->R;
	So = this->S;
	Mu = this->M;
	while(Re != NULL){ // initialize Receievers
		board[Re->getpos().getx()][Re->getpos().gety()] = Re->getReceiverID();
		Re = Re->getNextReceiver();
	}
	while(So!= NULL){ //initialize Sources
		board[So->getpos().getx()][So->getpos().gety()] = So->getSourceID();
				So = So->getNextSource();
	}
	while(Mu!=NULL){ // initialize Mules
		board[Mu->getpos().getx()][Mu->getpos().gety()] = Mu->getMuleID();
		Mu = Mu->getNextMule();
	}
	 // for-loop, using to print out the field
		for (int i=-1; i<=Size; i++){
	                 for(int j=0;j<Size; j++){
			    	   // using to print out the top and bottom border of the field
	                	 if(i==-1 || i==(Size)){
			    		   printf("___"); // using character '_' to print out the up and bottom border
			    		}
			    	   else{ if(j==0){
			    		   printf("\n|%3d", board[j][i]); // print out the left border of the field
			    		   }
			    	   else { if(j== Size-1){
			    		   if (i!= Size-1){
			    		   printf("%3d|", board[j][i]);// print out the right border of the field
			    		   }
			    		   else printf("%3d|\n", board[j][i]); // fill in the number to the field
			    	   }

			    	   else printf("%3d" ,board[j][i]);
			    		   }
			}
			       }

		   }
				printf("\n");
	}
