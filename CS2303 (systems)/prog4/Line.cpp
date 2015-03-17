#include <iostream>
#include <string>
#include "Tree.h"
#include "Line.h"
#include "Word.h"
using namespace std;


void Line::makeline(int linenumber)
{
	linenumber=linenumber;
	linepointer=NULL;
}


void Line::insert(Line *oldline , Line newline)
{
	Line *currentline;
	Line *nextline;

	nextline= &newline;
	currentline=oldline;

	if(currentline==NULL) // insert newline if current pointer is NULL
	{
		oldline= nextline;
	}

	else 
		{ 
			while(currentline!=NULL)  // recurse to find the end of list
			{
				currentline=currentline->linepointer;
				
					if(currentline->linepointer==NULL)
					{
						currentline->linepointer=nextline;
						break;

					}
			} 


		}

}

void Line::print_line(Line *sPtr)
	{
		// check if the tree is empty before traversing
		if (sPtr!=NULL)
		{
			print_line(sPtr->linepointer);
			cout<< " "<< sPtr->linenumber;
		}

	}