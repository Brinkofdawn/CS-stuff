//============================================================================
// Name        : Program 5
// Authors      :  Donti and  Ly
// Description : Lab5 in C++, Ansi-style
// Team 	   : 3B
//============================================================================

 
Section C03
In this program, we define several classes to do the simulation.
First, we defined a class called Lists. This class is used to store the list of Source, Mule and Receiver IDs that one packet has to go through. It has functions to insert a new node into the end of the list and remove the node at the front. These functions work correctly. 

Next, we defined a class called Packet. Packet will contain all of the information needed for simulation. We defined function enqueue and dequeue to manipulate a list of packets(  ) and 2 other functions , updateSourceList() to update the list of source ID stored in each Packet and updatepropagationtime() to update propagation time of the packet( ). These functions work correctly.
We have a class called position. Class position contain the x position and y position and direction of a Mules, a Source or a Receiver. We used the function rand() to generate random Mules, Source and Receiver position. We also have function to calculate distance between Sources, Mules and Receivers to calculate propagation times. We have a function called equalpos to check if 2 positions is equal or not and a function to update the x-y position in the given direction. They all work correctly. .

Then we define 3 classes. Class Source, Class Mules and Class Receiver. These classes contained function to initialize the position, to moving mules over the map and to sending packet from senders to mules, between mules and from mules to receiver. We defined a list of Packet called the waiting list. The waiting list was used to store all of the packet that is dequeued out from a source or a mule but still not finish propagation time to arrive at the next mule. There are 2 functions for sending packet in the class Mules: one is used to send packets from mules to waiting list for other mules or receivers. This function will check the transmission time and find the next destination in the packet’s ListOfSource to send the packet to the waiting list with proper propagation time. We defined a helper function to take in an ID and find the correct Source, Mule, or Receiver with this ID to calculate the exact distance for propagation time.

The other function for sending packet in the class Mules is to send packets from the waiting list to the mules. We used a helper function to find the correct destination for a packet (as mentioned above), check the propagation time of the packet, update the transmission time of the packet and send the packet to its next destination.
For moving mules, first we defined a function to initialize the position of the mules and their initial direction. The positions and initial directions was assigned randomly by using functions in class Position. For the initialize step, we define a function to check if the initialize function provided two mules at the same position. If yes, the position will be updated until there is no two or more mules at the same position. To move the mules, we defined a function that recall the function to update position in class Position.

For the class Mules, all of the functions for moving mules are working correctly. For the function for sending packet, the ideas and concept and procedure was right, however there are some minor problems that make the program can’t work correctly. 
In the class Mules, the function enqueue() and dequeue() was   and the rest was  .

In the class Source, we defined similar functions to class Mules. The initializing position step work fine, however the sending may have some small problem. The class Source was  

In the class Receiver, we define similar function. The functions to initialize work correctly, and the function to calculate size, specific size from Sources and total delay works correctly.
In the class Board, we have the function to print out the Manet Map. All of the function works correctly.

We design a function called Manet where we run the simulation. First, we initialized the initial position of Source, Mule and Receiver. Then we defined a counter call clock. Clock will count for each simulation inside a while-loop. The while-loop will run until all of packet arrived at the receiver. For each loop, we will check for the transmission time, propagation time, and sending packet. For each 10sim, the mules will be moved. This function, in our opinion, works fine. This function was  .
We together finish the main function. In the main function, after initialize a list of sources, a list of mules and a list of receiver, we will take in the input and add them to sources. After that, we called the function Manet, which will do simulation step. And I think the main problem with our program is in the main function. Maybe because of initializing step that create some NULL pointer so the program is segmentation fault. 
In this program, I believe, all of our idea and procedure for solving this simulation problem is correct. However, some minor problems exists and ruined the program.


To make: make 


to run program : ./Program5 (command line args) <(file to take in)

ex. ./Program5  20 10 24 30 <test.txt