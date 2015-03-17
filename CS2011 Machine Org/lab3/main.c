//Arun Donti
// CS23003 C03
// Lab 3

#include "lab3.h"

int main(int argc, char *argv[])
{
	EventPtr startPtr=NULL;

	if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "You must specify how many nodes to read" );
    }
     else 
    {
    	int num;
		num = atoi(argv[1]);       

    
        
		 for (int i = 0; i < num; i++)
			{
			double pid;
			int arrival,cpu;
			scanf("%lf %d %d",&pid, &arrival, &cpu);
			add_event(&startPtr,pid,arrival,cpu);

			}
          
       	}




	
	print_eventlist(startPtr);

	for(int j =0; j<NUMOUT ; j++)
	{
		get_nextevent(&startPtr);

	} 
		printf("\n current event list \n");
		print_eventlist(startPtr);

	return 0;
}
struct event makeEvent(int pid, int arrival, int cpu){
	EventPtr tempPtr;
	Event thisEvent={pid, arrival, cpu, tempPtr};
return thisEvent;
}

void add_event(EventPtr *sPtr,double pid, int arrival, int cpu){
	EventPtr newPtr;//pointer to a new node
	EventPtr previousPtr; // point to previous node
	EventPtr currentPtr; // point to current node

	newPtr=malloc(sizeof(Event));
	if(newPtr!=NULL)// if there is no nodes add to top of list
	{
	newPtr->pid= pid;
	newPtr->arrival=arrival;
	newPtr->cpu=cpu;
	newPtr->nextPtr=NULL;// no linking to another event

	previousPtr=NULL;
	currentPtr= *sPtr;
	//loop to find correct position on list
	while(currentPtr != NULL && arrival>currentPtr->arrival){
		previousPtr=currentPtr;
		currentPtr= currentPtr->nextPtr;
	}

	if(previousPtr == NULL){ // insert at ebggining of list
		newPtr->nextPtr = *sPtr;
		*sPtr = newPtr;
	}
	else{// insert between previousPtr and currentPtr
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	
		}

	}
}

int isEmpty(EventPtr sPtr) // finds current number of nodes
{
 
return sPtr ==NULL;
}


struct event get_nextevent(EventPtr *sPtr)  // returns the first event in he queue and shifts everything else left
{
	
	EventPtr tempPtr; // use to free space
	tempPtr=*sPtr;
	*sPtr = (*sPtr)->nextPtr;
	printf("\n Just took off %lf %d %d \n",tempPtr->pid, tempPtr->arrival, tempPtr->cpu);
	return makeEvent(tempPtr->pid,tempPtr->arrival,tempPtr->cpu) ;
	// not freeing because will be freed later in program 3
} 

void  print_eventlist(EventPtr currentPtr)
{	
   if (isEmpty(currentPtr))
   {
   	printf("empty list\n");
   }
   else{
   while(currentPtr != NULL){// move on to next pointer when not at end of list
   	printf("\n %lf %d %d ",currentPtr->pid, currentPtr->arrival, currentPtr->cpu);
   	currentPtr = currentPtr->nextPtr;
   }

printf("\n");
 }
}