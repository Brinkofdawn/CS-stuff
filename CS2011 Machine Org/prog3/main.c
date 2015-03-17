//Arun Donti
// CS23003 C03
// Prog 3

#include "prog4.h"

int main(int argc, char *argv[])
{
	EventPtr startPtr=NULL;
	EventPtr compPtr=NULL;
	totalcputime=0;
	counter=0;
	//sum=0;

	if ( argc != 3 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "You must specify how many nodes to read" );
    }
     else 
    {
    	int num,slice;
		num = atoi(argv[1]);
		slice = atoi(argv[2]);       

        processtimes=malloc(sizeof(double)*num); // making a sudo array to hold sum values for vairance calculations

        
		 for (int i = 0; i < num; i++)
			{
			double pid;
			int arrival,cpu;
			scanf("%lf %d %d",&pid, &arrival, &cpu);
			add_event(&startPtr,pid,arrival,cpu);

			}
			addtoend(&startPtr,-1,9999999,0);// null event to keep queue from being empty
			addtoend(&compPtr,-1,-1,-1);

			if (slice==0)
			{
				Fifoqueue(&startPtr,compPtr);
			}

			else
			{	
			
			while(counter<CYCLES)// breaking out of while loop if idle for 500 cycles
				{
				
				if(startPtr->pid != -1)// checking if not empty
					{	

					while(startPtr->arrival <= totalcputime && startPtr->pid != -1)
						{
						Event tempNode= get_nextevent(&startPtr);
						 // keep the null node in the first queue
						addtoend(&compPtr,tempNode.pid,tempNode.arrival,tempNode.cpu); // add to end of queue
						}
						RoundRobin(&compPtr,slice);
						totalcputime++;
						
							
					}



				else 
					{ 	

						counter++;
						totalcputime++;
						
					}
					
					while(startPtr->pid==-1 && compPtr!=NULL && counter!=500) // if the queue isnt empty then empty it !
					{
						RoundRobin(&compPtr,slice);
					}


				}
				

			}
			calcVariance(num);

			}
			  return 0;
		}
          
       	
 


void Fifoqueue(EventPtr *sPtr,EventPtr comp)
{ // create the queue for Fifo
		int timecounter =0;
			EventPtr tempPtr; //
			tempPtr=*sPtr;

	while(sPtr!=NULL){

			if(tempPtr->arrival == timecounter)
			{
				
				Event tempNode= get_nextevent(sPtr);
				 // keep the null node in the first queue
				if(tempNode.pid!=-1)
				{
				addtoend(&comp,tempNode.pid,tempNode.arrival,tempNode.cpu);
				Fifo(&comp,timecounter);
				}
				else
				{
					break; // leave the null pricess in initial queue
				}
			}

			
			
			else
			{
				timecounter++;
			}
		}
}


void Fifo(EventPtr *sPtr, int time) // logic for output of Fifo
{
	static int totaltime= 0;
	static int hold=0;
	EventPtr tempPtr;
	tempPtr=*sPtr;
	*sPtr = (*sPtr)->nextPtr;
	// what the totaltime should equal if the arrival time is gretaer than or equal to, or less than
	
	if (tempPtr->arrival >= totaltime ) 
	{
		totaltime= tempPtr->arrival + tempPtr->cpu;
	}
	else if (tempPtr->arrival < totaltime )
	{	
	{
		printf("\n waiting...\n");
	}
		totaltime= totaltime+ tempPtr->cpu;
	}
	printf("Process %5.0lf arrived at %d and left at %d \n",tempPtr->pid, tempPtr->arrival, totaltime);
		sum+=(totaltime-tempPtr->arrival);
		processtimes[hold]=totaltime-tempPtr->arrival;

	free(tempPtr);

}


void RoundRobin(EventPtr *comp,int slice)//queue for Round Robin
	{ // create the queue for Fifo
	EventPtr tempPtr; //
	tempPtr=*comp;		
		
		if(tempPtr->pid !=-1)	
		{
						//printf("dll\n");
					 if(tempPtr->cpu > slice) // what to do if cpu time is greater than slice
							{Event fornow;
								tempPtr->cpu=tempPtr->cpu-slice; // subtract the amount of cpu time already processed
								fornow =makeEvent(tempPtr->pid,tempPtr->arrival,tempPtr->cpu);
								*comp=(*comp)->nextPtr;
								addtoend(comp,fornow.pid,fornow.arrival,fornow.cpu);
								totalcputime=totalcputime+slice;

								counter=0;
											//printf("dp\n");
							}
									
									
									//printf("do\n");
										

					 else if(tempPtr->cpu <= slice) // get rid of event if  cpu time is <= timeslice
						 	{	static int hold=0;
						 		counter=0;
						 		totalcputime=totalcputime+tempPtr->cpu;
								printf("Process %5.0lf arrived at %d and left at %lf \n",tempPtr->pid, tempPtr->arrival, totalcputime);
								sum+=(totalcputime-tempPtr->arrival);
								processtimes[hold]=totalcputime-tempPtr->arrival;
						 		*comp=(*comp)->nextPtr;
						 		free(tempPtr);
								 
							}
								 			
				
						 	
						 				//printf("da\n");
		}
					 
				
					

			else if (tempPtr->pid==-1 && tempPtr->nextPtr !=NULL)
			{   
				printf("waiting.....\n"); // waitng for new process to come into queue
				looptoend(comp);
				counter++;

			}

			else{
				counter++; // if the list is empty just exit the program
			}

					
										

					//printf("di\n");
				

}



	void looptoend(Event **sPtr) // takes the head pointer, moves it to the back of the queue and then shifts everything over to the left
		{
			Event *tempPtr=(*sPtr)->nextPtr;
			Event *currentPtr= *sPtr;
			Event *head= *sPtr;

			while(currentPtr->nextPtr != NULL)
			{
				currentPtr =currentPtr->nextPtr;
			}

			//put head to end
			currentPtr->nextPtr = head;

			//set next to null and point start to the previous second in list.
			head->nextPtr=NULL;
			*sPtr= tempPtr;



		}

	
struct event makeEvent(double pid, int arrival, int cpu){
	EventPtr tempPtr;
	tempPtr = NULL;
	Event thisEvent={pid, arrival, cpu, tempPtr};
return thisEvent;
}


void addtoend(EventPtr *sPtr,double pid, int arrival, int cpu)
	{	

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
		//loop to end of list
			while(currentPtr != NULL){
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

void calcVariance(int num)
{ 
	double vartotal;
	vartotal=0;
	mean=sum/num;
	for(int i =0; i<num; i++)
	{   double temp= processtimes[i] - mean;// temporarily store value
		vartotal= vartotal+ temp * temp;

	}
	vartotal=vartotal/(num-1);
	printf("\n The mean of the data is %lf variance of the data is %lf \n", mean, vartotal);
}





struct event get_nextevent(EventPtr *sPtr)  // returns the first event in he queue and shifts everything else left
{
	
	EventPtr tempPtr; // use to free space
	tempPtr=*sPtr;
	*sPtr = (*sPtr)->nextPtr;
	return makeEvent(tempPtr->pid,tempPtr->arrival,tempPtr->cpu) ;
	 

printf("\n");
 }
