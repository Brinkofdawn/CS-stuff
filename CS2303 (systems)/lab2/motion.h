#include <stdio.h>
#define LENGTH 18 //Length of board
#define WIDTH 12 //Width of board
#define SAMPLES 8 // amount of samples in file

//Prototypes
int motion (int nodeid, int row, int column, int direction);
void initfield();
void printfield();

enum direction {Right, Left, Up, Down}; // directions of the numbers
int field [WIDTH] [LENGTH]; // the array for the board
int nodeid,row,column,direction;// the 4 ints required to identify each thing on the board
FILE *infile;// file you are taking in
infile = fopen("SAMPLES.txt", "r");       // using relative path name of file
	if (infile == NULL) {
	  // assume that Error is some error function that handles the error, maybe
		// printing out the passed error string and calling exit(1);
		Error("Unable to open file."); 
	}