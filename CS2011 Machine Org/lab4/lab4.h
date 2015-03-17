//Arun Donti
// CS23003 C03
// Lab 4

#include <stdlib.h>
#include <stdio.h>


struct tree // struct to hold all data
{	
	double id; // student id 
	float first;    // first test
	float second; // second test
	float third; // third test
	double mean; // average score
	struct tree *leftPtr; // pointer to another struct of the same type
	struct tree *rightPtr; // pointer to another struct of the same type
} ;
typedef struct tree Tree;
typedef Tree *TreePtr;

//prototypes


void insert(TreePtr *sPtr, Tree thistree);
void print_tree(TreePtr sPtr);
struct tree makeBranch(double id,float first, float second, float third);
