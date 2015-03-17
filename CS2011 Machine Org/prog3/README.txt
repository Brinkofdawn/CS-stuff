


Author:				Arun Donti
Date:				2/13/13
Project ID:			prog 3
CS Class:			CS 2303
Programming Language:		C .


Problem Description:		Creating Event Queues




How to build the program:	make

How to run the prorgram ./main (int for how many processes) (int for time slice, 0 for Fifo)  <prog4.dat
						ex. ./main 36 10  <prog4.dat

Program Source:			prog4.h main.c

Sample Output Files:	RoundRobinslice10.txt, Fifo.txt	



How Round Robin Works:

Because queues segfault when actually empty, I entered processes with pid -1 to act as a sentinel to act as if a list is empty.

So to begin my RR I iterate time in the main. While the cpu hasn't idled for too long ( I set it to 500 cycles , it can be changed by the define statement in prog4.h). If the feeder queue isnt empty and the the arrival time of the first process in the queue is lessthan or equal to the total cpu time it will send the process to the back of the cpu queue. Once it has sent all the processes with specific arrival times to the back it will add one to the total cpu times. Else if the feeder queue is empty it will just runt he round robin until the cpu queue is empty. The actual RoundRobin function will check the first thing in the cpu queue, if it the total cpu time required is greater than the time slice it will send the process to the back of the queue with the time slice subtracted from its total cpu time and add the time slice value to the totalcputime. If total time required is less than the time slice it will remove the process from the queue and add the cpu time of that process to the total cpu time. If there is nothing in the cpu queue it will wait for the feeder queue to send it data. the Round Robin will shut down if the feeder queue has not sent the cpu queue data in a specific amount of cycles.


How Fifo Works:

Fifo will check if the first thing in the feeder queue to the total cpu time. If it less than or equal to the total cpu time it will send it to the process queue  and add the time slice to the total cpu time and then remove that prcoess from the queue.


Variance:

I have pointer called processtimes that I give it the memory of a double multiplied by the number of arguements. Basically it is an array that stores specific values to be used for variance calculations later on.









