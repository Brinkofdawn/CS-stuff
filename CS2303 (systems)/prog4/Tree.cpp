#include <iostream>
#include <string>
#include "Tree.h"
#include "Line.h"
#include "Word.h"
using namespace std;



void Tree::addtree(Word word, Tree *treepointer)
{
	Tree *previousPtr;
	Tree *currentPtr;
	Tree *newPtr = new Tree;

	//newPtr=malloc(sizeof(Tree));
	newPtr->word= word;
	newPtr->leftpointer= NULL;
	newPtr->rightpointer=NULL;
	
	currentPtr=treepointer;

	if (currentPtr==NULL) // set the null pointer to the treepointer
	{
		treepointer= newPtr;
		
	}

	else
	{
		if (strcmp(((newPtr->Word).name),(currentPtr->Word).name) < 0)// if new word is less than

		{
			if (currentPtr->leftpointer==NULL)
			{
				currentPtr->leftpointer=newPtr;
			}

			else 
			{
				addtree(word, currentPtr->leftpointer)
			}
		}


		else if (strcmp(((newPtr->Word).name),(currentPtr->Word).name) >0)// if new word is greater than

		{
			if (currentPtr->rightpointer==NULL)
			{
				currentPtr->rightpointer=newPtr;
			}

			else 
			{
				addtree(word, currentPtr->rightpointer);

			}
		}

		else

		{
			Line newline;		// if already in the tree increment the amount and add the linenumber
			newline= word.line;
			currentPtr->word.amount++;
			Line.insert(currentPtr->word.line, newline);
		}



	}
}


void Tree::print_tree(Tree *sPtr)
	{
		// check if the tree is empty before traversing
		if (sPtr!=NULL)
		{
			print_tree(sPtr->leftPtr);
			cout<< sPtr->word.word <<"appears"<<sPtr->word.amount<<"times on line(s)";
			while(sPtr->word.lines!=NULL)
			{
			Line.print_line(sPtr->word.lines);
			}
			print_tree(sPtr->rightPtr);
		}

	}
