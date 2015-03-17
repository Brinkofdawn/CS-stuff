//============================================================================
// Name        : Lab5
// Author      : Arun Donti and Thinh Ly
// Description : Lab5 in C++, Ansi-style
// Team 	   : 3B
//============================================================================


The program preloads 100 packets each into the initial S1 and S2 queues and processes each packet (or event) giving it a id number, a source queue and an arrival time. It will then send each event to the next queue keeping track of the totaltime in the queue and the total time of the simulation. Once the packet reaches R1 it will calculate the propogation time of the simulation. There are a few variables also there to keep track of the maximum sizes of M1 and M2 and then print them out later.



How to make:

make

How to clean.o files:
make clean

How to run program:

./lab5 > packetsim.txt
