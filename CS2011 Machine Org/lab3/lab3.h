//Arun Donti
// CS23003 C03
// Lab 3

#include <stdlib.h>
#include <stdio.h>
#define NUMOUT 2  // the number of nodes to be taken off the queue


struct event // struct to hold all data
{
	double pid;    // process id
	int arrival; // arival time
	int cpu; // how much cpu time it takes
	struct event *nextPtr; // pointer to another struct of the same type
} ;
typedef struct event Event;
typedef Event *EventPtr;

//prototypes

void add_event(EventPtr *sPtr,double pid, int arrival, int cpu);
struct event get_nextevent(EventPtr *sPtr);
void print_eventlist(EventPtr currentPtr);
struct event makeEvent(int pid, int arrival, int cpu);
int isEmpty();