


void initfield(){
    for (int columns = 0; columns < LENGTH +2;  columns++ )//setting specified playing space + edges to borders
    {
        //Create the borders
        for (int rows = 0; rows < WIDTH+2; rows++ )//recursing through rows
         { 
         field[columns][rows]=0;
    }//end second for loop
  }//end first for loop


void printfield(){//print current game field
  for (int i = 0; i < WIDTH; ++i)
  {
    printf("-");//top border
  }
  printf("\n");
      for ( int columns = 0; columns < LENGTH ;  columns++ )// recursing through columns
    {printf("|");//left border
        for (int rows = 0; rows < WIDTH; rows++ )//recursing through rows
         { 
        printf("%3d",field[columns][rows]);
   

    }
     printf("|\n"); // right border plus newline for each row
  }
   for (int i = 0; i < WIDTH; ++i)
  {
    printf("-");//bottom border
  }
}