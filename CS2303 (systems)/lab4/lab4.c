#include "lab4.h"

//Arun Donti
// CS23003 C03
// Lab 4

int main(int argc, char *argv[])
{
	TreePtr startPtr=NULL;

	if ( argc != 2 ) /* argc should be 3 for correct execution */
    {
       
        printf( "You must specify the number of students" );
    }

    int num;
	num = atoi(argv[1]); 

	for (int i = 0; i < num; i++) // add events to initial queue
			{
			Tree temptree;
			double id;
			int first,second,third;
			printf("Enter student id and test scores\n");
			scanf("%lf %d %d %d",&id,&first, &second, &third);
			temptree=makeBranch(id,first,second,third);
			insert(&startPtr,temptree);
			}
}




struct tree makeBranch(double id,int first, int second, int third){
	TreePtr LeftPtr =NULL;
	TreePtr RightPtr= NULL;

	double mean;
	mean= (first+second+third)/3;
	Tree thisTree={id, first, second, third,mean,LeftPtr,RightPtr};
return thisTree;
}


void insert(TreePtr *sPtr, Tree thistree)

{
// if tree is empty
	if(*sPtr ==NULL)
	{
		*sPtr =malloc(sizeof(Tree));

	//if given memory assign data
			if(*sPtr !=NULL)
			{	
				(*sPtr)->id= thistree.id;
				(*sPtr)->first= thistree.first;
				(*sPtr)->second= thistree.second;
				(*sPtr)->third= thistree.third;
				(*sPtr)->mean= thistree.mean;


			}	

			else
			{
				printf("Oh no the tree has been cut down!"); // no memory left

			}


	}

	else
	{	
		// data insert to less if the mean is smaller
		if(thistree.id <(*sPtr)->id)
		{
			insert(&((*sPtr)->leftPtr), thistree);
		}

		else if (thistree.id >(*sPtr)->id)
		{
			insert(&((*sPtr)->rightPtr), thistree);
		}
	}

	
}

void print_tree(TreePtr sPtr)
	{
		// check if the tree is empty before traversing
		if (sPtr!=NULL)
		{
			print_tree(sPtr->leftPtr);
			printf("\n Student ID:%lf  First Score:%d  Second Score:%d Third Score:%d Mean:%lf \n", sPtr->id,sPtr->first,sPtr->second,sPtr->third,sPtr->mean);
			print_tree(sPtr->rightPtr);
		}

	}