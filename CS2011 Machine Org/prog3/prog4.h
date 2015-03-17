//Arun Donti
// CS23003 C03
// Prog 4

#include <stdlib.h>
#include <stdio.h>
#define CYCLES 500  // the max number of cycles to idle for


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
struct event makeEvent(double pid, int arrival, int cpu);
void Fifoqueue(EventPtr *sPtr,EventPtr comp);
void RoundRobin(EventPtr *comp,int slice);
void addtoend(EventPtr *sPtr,double pid, int arrival, int cpu);
void Fifo(EventPtr *sPtr, int time);
void looptoend(Event **sPtr);
void calcVariance(int num);


//globals

double totalcputime; // current itme in the cpu
double sum; // used for mean and variance calculations
double mean; // mean result
double *processtimes; // array for value storage
int counter;// counter to break our of while loop in RR
