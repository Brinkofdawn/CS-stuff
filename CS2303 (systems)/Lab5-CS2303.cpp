//============================================================================
// Name        : Lab5-CS2303.cpp
// Author      : Thinh Ly
// Version     :
// Copyright   : Your copyright notice
// Description : Lab5 in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
using namespace std;
int time_slice;

// define a new type of structure call events, which contain 3 float variables and one pointer to another events
struct events{
	 int process_id; //the first variable of the struct events : process_id
	 int arrival_time;//the second variable of the struct events : arrival_time
     int tranmissiontime;
     int propagationtime;
	 struct events *link;//the fourth variable of the struct events : a pointer to another events
 } ;
   typedef struct events Events; //define an alias synonym to struct events
   typedef Events *Link; //define a pointer to an events link
   Link array1[200];
   Link array2[200];
   Link array3[200];
void enqueue(Link *headPtr , Link *tailPtr, int p_id , int a_time, int trans, int prop){
	Link newPtr; // the pointer to a new events
	newPtr = new Events(); // allocate an address for new event
	if(newPtr != NULL){
		newPtr->process_id = p_id;// input in the new events with the given information
		newPtr->arrival_time = a_time;
		newPtr->tranmissiontime =trans;
		newPtr->propagationtime =prop;
		newPtr->link =NULL;
		//check if the the queue is empty or not, if empty, the new event will be the first event of the queue
		if (*tailPtr == NULL){
			*headPtr = newPtr;

			}
	    // if not empty, the new events will be inserted to the end of the queue
		else {
		(*tailPtr)->link = newPtr;
		}
		*tailPtr = newPtr;
	}
	else printf("there is no memory");
}
Link dequeue(Link *headPtr, Link *tailPtr){
	Link tempPtr;
	tempPtr = NULL;
	// check if a queue is empty, if empty the function will set the queue to empty
	if (*headPtr == NULL){
		*tailPtr =NULL;
	}
	// if a queue is not empty, remove the first event of the queue
	else {
		tempPtr = *headPtr;
		*headPtr = (*headPtr)->link;
		}
	   return tempPtr; // return the remove events
}
void insert(int P_id , int a_t,int trans, int prop,Link *sptr){
	 Link newPtr; //define a newPtr to a new event
	 Link curPtr; //define a curPtr to the current events
	 Link prePtr; //define a prePtr to the previous events
 newPtr = new Events(); // assigned a space in memory for newPtr
 if (newPtr != NULL){
	 newPtr->link = NULL; // assigned a value for the link of the new events
	 newPtr->process_id=P_id; //assigned a value for the process id of the events
     newPtr->tranmissiontime= trans;
     newPtr->propagationtime= prop;//assigned a value for the cpu time of the events
	 newPtr->arrival_time =a_t; //assigned a value for the arrival time of the events
	 prePtr = NULL; // assigned a NULL value for the prePtr

    curPtr = *sptr;// assigned the current pointer to the first pointer of the list
    // run for-loop to find a proper place for the new events to be inserted
    while (curPtr != NULL && curPtr->arrival_time < newPtr->arrival_time){
    	prePtr = curPtr;
    	curPtr = curPtr->link;
    }
    // insert a new events into the list if its position is in the first position of the list
    if (prePtr == NULL){
    	newPtr->link = curPtr;
    	*sptr = newPtr;
    }
    // insert an events into a specified position of the list in specific order
    else{
    	prePtr->link = newPtr;
    	newPtr->link = curPtr;
    }
 }
 else {
	 printf("No memory"); //printf an statements if there is no memory for the new events
 }
 }
void addto1(Link pointer){
	int i;
	for(i=0; i<200; i++){
        if (array1[i]==NULL){
        	array1[i] = pointer;
        }
        else continue;
	}
}
void addto2(Link pointer){
	int i;
	for(i=0; i<200; i++){
	        if (array2[i]==NULL){
	        	array2[i] = pointer;
	        }
	        else continue;
		}
}
void updatearray1(){
	int i;
	for(i=0;i<200;i++){
		if(array1[i]!= NULL){
			array1[i]->propagationtime= array1[i]->propagationtime-1;
		}
		else continue;
	}
}
void updatearray2(){
	int i;
		for(i=0;i<200;i++){
			if(array2[i]!= NULL){
				array2[i]->propagationtime= array2[i]->propagationtime-1;
			}
			else continue;
		}
}
void updatearray3(){
	int i;
			for(i=0;i<200;i++){
				if(array3[i]!= NULL){
					array3[i]->propagationtime= array3[i]->propagationtime-1;
				}
				else continue;
			}
}
void updatetranstime(Link *headPtr){
if(*headPtr != NULL){
    	(*headPtr)->tranmissiontime = (*headPtr)->tranmissiontime-1;
    }
}
bool checktranstime(Link *headPtr){

	return ((*headPtr)->tranmissiontime == 0);
}

void FCFS(Link *EListPointer, Link *ElisttailPointer, Link *S1Headpointer, Link *S1tailpointer, Link *S2Headpointer, Link *S2Tailpointer, Link *M1Headpointer, Link *M1Tailpointer, Link *M2Headpointer, Link *M2Tailpointer){
    int k,j,n;
    int clock;
    Link temPtr;
    clock = 0;
    k=0;
    j=0;
    n=0;
    //for (int i=0 ; i<200; i++){
    	//array1[i] = NULL;
    	//array2[i] = NULL;
    //}
     while (*EListPointer != NULL){
    	 if (clock == 0){
    		 enqueue(S1Headpointer,S1tailpointer, (*EListPointer)->process_id, (*EListPointer)->arrival_time, (*EListPointer)->propagationtime,(*EListPointer)->tranmissiontime);
    		 dequeue(EListPointer,ElisttailPointer);
    	 }
    	 clock = clock + 1;
    	 updatetranstime(S1Headpointer);
    	 updatetranstime(S2Headpointer);
    	 updatetranstime(M1Headpointer);
    	 updatetranstime(M2Headpointer);
         updatearray1();
         updatearray2();
         updatearray3();
         if((*S1Headpointer)!= NULL){
      if(checktranstime(S1Headpointer)){
    	  temPtr = *S1Headpointer;
    	  dequeue(S1Headpointer, S1tailpointer);
    	  array1[k] = temPtr;
    	  k = k+1;
    	  enqueue(S1Headpointer,S1tailpointer, (*EListPointer)->process_id, clock, (*EListPointer)->propagationtime,(*EListPointer)->tranmissiontime);
    	  dequeue(EListPointer,ElisttailPointer);
    	  }
      }

       if((*S2Headpointer)!= NULL){
      if(checktranstime(S2Headpointer) && clock >= 3){
    	  temPtr = *S2Headpointer;
    	  dequeue(S2Headpointer, S2Tailpointer);
    	  array1[k]=temPtr;
    	  k=k+1;
    	  enqueue(S1Headpointer,S1tailpointer, (*EListPointer)->process_id, clock, (*EListPointer)->propagationtime,(*EListPointer)->tranmissiontime);
    	  dequeue(EListPointer,ElisttailPointer);

    	       }
    	  }
       if((*M1Headpointer)!=NULL){
    if(checktranstime(M1Headpointer)){
    	temPtr = *M1Headpointer;
    	dequeue(M1Headpointer, M1Tailpointer);
    	array2[j]= temPtr;
    	j=j+1;
    }
}
       if((*M2Headpointer)!=NULL){
       if(checktranstime(M2Headpointer)){
       	temPtr = *M2Headpointer;
       	dequeue(M2Headpointer, M2Tailpointer);
       	array3[n] = temPtr;
        n=n+1;
       }
}

       for(int i=0;i<200;i++){

    	   if(array1[i] != NULL){
    		   if(array1[i]->propagationtime==0){
    			   enqueue(M1Headpointer, M1Tailpointer, array1[i]->process_id, array1[i]->arrival_time, 2, 3);
    			   array1[i]= NULL;
    			   printf("2");
    		   }
    	   }
    	   else continue;
    	   if(array2[i] != NULL){
    		   if(array2[i]->propagationtime==0){
    			   enqueue(M2Headpointer, M2Tailpointer, array2[i]->process_id, array2[i]->arrival_time, 2, 5);
    			   array2[i]= NULL;
    		   }
    	   }
    	   else continue;
    	   if(array3[i] != NULL){
    		   if(array3[i]->propagationtime==0){
    		          printf("%3d,  %3d  , %3d\n",array3[i]->process_id, array3[i]->arrival_time, clock);

    		       			   array3[i]= NULL;
    	   }
       }
    	   else continue;
}
}
}


	int main(int argc, char* argv[]) {
	    int NumOfInput; // command line argument
	    int i, P_id , arr_time; // input and counter
	    Link EList = NULL,  Elisttail= NULL,  S1Head= NULL,  S1tail=NULL, S2Head=NULL, S2Tail=NULL, M1Head=NULL, M1Tail=NULL, M2Head=NULL,M2Tail=NULL,newPtr;
	    EList = NULL;
	    newPtr = new Events();
	    Elisttail = NULL;
	  NumOfInput = atoi(argv[1]);
	  time_slice = atoi(argv[2]);
	   printf("Please type in the processes\n");
	   for(i=0 ; i < NumOfInput ; i++){
		   scanf("%d" , &P_id);  // read in the input
		   scanf("%d" , &arr_time);
		   newPtr->link = NULL; // assigned a value for the link of the new events
		   newPtr->process_id=P_id; //assigned a value for the process id of the events
		   newPtr->tranmissiontime = 1;
		   newPtr->propagationtime = 2;//assigned a value for the cpu time of the events
		   newPtr->arrival_time =arr_time; //assigned a value for the arrival time of the events


		   insert(P_id , arr_time,1, 2,&EList); // insert these event into a event-list in chronological order

		if (i == NumOfInput -1){
			 Elisttail = newPtr; // set the value for the last event pointer of the event list
	   }
	}
	   FCFS(&EList, &Elisttail,  &S1Head,  &S1tail, &S2Head, &S2Tail, &M1Head, &M1Tail, &M2Head,&M2Tail); // run FCFS process
	return 0;
}
