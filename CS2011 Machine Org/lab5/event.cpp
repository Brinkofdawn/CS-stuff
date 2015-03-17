#include "event.h"
#include <stddef.h>
#include <string>


event::event() 
{  // default constructor

}

event::event(string source,int pid,int arrival, event *eventPtr) 
{  // constructor
		this->source=source;
		this->pid= pid;
		this->arrival=arrival;
		this->eventPtr= eventPtr;
}


void event::addto(event **top) // adds an event to the back of a linked lisr
{

		event *newPtr= new event;//pointer to a new node
		event *previousPtr; // point to previous node
		event *currentPtr; // point to current node


		if(newPtr!=NULL)// if there is no nodes add to top of list
		{
		newPtr->source=this->source;	
		newPtr->pid= this->pid;
		newPtr->arrival= this->arrival;
		newPtr->eventPtr=NULL;// no linking to another event

		previousPtr=NULL;
		currentPtr= *top;
		//loop to end of list
			while(currentPtr != NULL){
			previousPtr=currentPtr;
			currentPtr= currentPtr->eventPtr;
			}


		if(previousPtr == NULL){ // insert at end of list
		newPtr->eventPtr = *top;
		*top = newPtr;
		}
		
		else{// insert between previousPtr and currentPtr
			previousPtr->eventPtr=newPtr;
			newPtr->eventPtr=currentPtr;
	
		}
		

		}
}

int event::size(event **top) // returns size of node
{
	int count;
	count=0;

		event *previousPtr; // point to previous node
		event *currentPtr; // point to current node
		previousPtr=NULL;
		currentPtr= *top;
		//loop to end of list
			while(currentPtr != NULL){
			previousPtr=currentPtr;
			currentPtr= currentPtr->eventPtr;
			count++;

			}
		return count;

}


event event::get_nextevent(event **sPtr)  // returns the first event in he queue and shifts everything else left
{
	
	event *tempPtr; // use to free space
	tempPtr=*sPtr;
	*sPtr = (*sPtr)->eventPtr;
	return *tempPtr;
	 

 }

