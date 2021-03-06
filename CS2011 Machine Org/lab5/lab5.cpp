//============================================================================
// Name        : Prog5
// Author      : Arun Donti and Thinh Ly
// Description : Program 5 in C++, Ansi-style
//============================================================================



#include <cstdlib> 
#include <cstdio> 
#include <iostream>
#include "event.h"
#define PACKETS 100 // packets in each of the two starting queues
using namespace std;

int totalcputime;// total time in cpu
int counter1;// for M1 transmission time
int counter2;// for M2 transmission time
int M1biggest; // stores the largest queue size for M1
int M2biggest;// stores the largest queue size for M1
int S1timetotal;// keeping track of total response time of S
int S2timetotal; // keeping track of total response time of S2

int main()
{
	M1biggest=0; 
	M2biggest=0;
	totalcputime=0;
	counter1=0;
	counter2=0;
	S1timetotal=0;
	S2timetotal=0;
	// all of the different queues used in the program
	event* S1= new event(); 
	event* S2= new event();
	event* M1= new event();
	event* M2= new event();
	event* R1= new event();
	event dummy("none",-1,-1,NULL); // Null packet


for (int i = 1; i < PACKETS+1; i++) // fill both feeders with specified packet numbers
{
	event event1 ("S1",i ,i-1, NULL); // packets for S1
	event event2 ("S2",i,2+i, NULL);// packets for S2
	event1.addto(&S1);
	event2.addto(&S2);
}


while(S1 !=NULL || S2 !=NULL || M1 !=NULL || M2 !=NULL || R1 !=NULL) // checking if queues are empty
	{
		if(S1 !=NULL || S2 !=NULL)
		{
			if ( S1 != NULL ) // send a packet every second if cpu time isn't null
			{
				event temp= dummy.get_nextevent(&S1);
				temp.arrival=temp.arrival-2; //simulate propagation time
				temp.addto(&M1);
				totalcputime++;
			}

			if (totalcputime >= 3 &&  S2 != NULL )// send a packet every second starting at 3 if cpu time isnt null
			{
				event temp= dummy.get_nextevent(&S2);
				temp.arrival=temp.arrival-2; //simulate propagation time
				temp.addto(&M1);
				totalcputime++;
			}
		}
		else
		{
			totalcputime++;
		}



		if (M1 != NULL ) // sending packets from M1 to M2
		{	

			if (dummy.size(&M1)> M1biggest)
			{
				M1biggest=dummy.size(&M1);
			}

			if (counter1==2) // simulating transmission time 
			{
				event temp= dummy.get_nextevent(&M1);
				temp.arrival=temp.arrival-3; //simulate propagation time
				temp.addto(&M2);
				counter1=-1;
			}
			counter1++;
		}

		if (M2 !=NULL)// sending packets from M2 to R1
		{	

			if (dummy.size(&M2)> M2biggest)
			{
				M2biggest=dummy.size(&M2);
			}

			if (counter2==2)
			{
				event temp= dummy.get_nextevent(&M2);
				temp.arrival=temp.arrival-5; //simulate propagation time
				temp.addto(&R1);
				counter2=-1;
			}
			counter2++;


		}	

		if (R1 !=NULL)
		{
			
				event temp= dummy.get_nextevent(&R1);
				if(temp.pid>0)// block all the NUll pids
				{
				temp.arrival=totalcputime-temp.arrival;// store the response time in the event
				cout<<temp.source<<" number "<<temp.pid<<" total response time is " <<temp.arrival<<endl<<endl;
				

				// redirect the response time into proper variable to be stored
				if (temp.source=="S1")
				{
					S1timetotal+=temp.arrival; 
				}

				if (temp.source=="S2")
				{
					S2timetotal+=temp.arrival;
				}


				}
		


		}	




	}

	cout<< endl<<endl<<endl;
	// Print out all the calculated values
	cout<<"S1 average response time is "<< S1timetotal/(PACKETS+1)<<endl;
	cout<<"S2 average response time is "<< S2timetotal/(PACKETS+1)<<endl;
	cout<<"M1's biggest queue size was "<< M1biggest<<endl;
	cout<<"M2's biggest queue size was "<< M2biggest<<endl;

	return 0;
}
