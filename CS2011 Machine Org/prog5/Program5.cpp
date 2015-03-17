//============================================================================
// Name        : Program5.cpp
// Author      : Thinh Ly and Arun Donti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include "Board.h"
#include "Source.h"
#include "Mules.h"
#include "Receiver.h"
#include "position.h"
#include "Packet.h"
#include "Lists.h"

using namespace std;
enum direction{NotMove,EAST, WEST,NORTH, SOUTH}; // directions





// Arun Donti
void Manet(Source** S, Receiver** R, Mules** M, Packet** waitinglist, int Size, int total){
	int clock;
	Board* B;
	B = new Board(*R, *S, *M);
	clock =0 ;
	(*R)->initialize(Size);
		(*M)->initialize(Size); // initialize all the Sources, Receivers, and Mules
		(*S)->initialize(Size);
	     B->makeBoard(Size);
while((*R)->allsize(R) < total){

    (*M)->sendPacketToWaitingList(waitinglist, R);

    (*S)->sendPacketToWaitingList(waitinglist,M);

    // send packets to waiting list
    (*M)->sendPacketToMules(waitinglist,clock);

    (*R)->sendPacketToReceiver(waitinglist,clock);

    if(clock % 10 == 0){
    	(*M)->MovingMules(Size-1);
    	B = new Board(*R, *S, *M);
    	B->makeBoard(Size);
    }
    (*M)->updatetransmissiontime();

    (*S)->updatetransmissiontime();
    (*waitinglist)->updatepropagationtime();


    clock++;

}


// Thinh Ly
}
int main(int argc, char* argv[]){
	int sNum , mNum, Rnum, Size;
	int sourceID, arrival_time, packet, packetsize, Sr_size, Sr;
	Packet* waitingList = new Packet();
	Packet* SR = new Packet();
	Lists* L = new Lists();
	Source* S = new Source();
	Mules* M = new Mules();
	Receiver* R = new Receiver();
	S->setNextSource(NULL);
	M->setNextMule(NULL);
	R->setNextReceiver(NULL);
	L= NULL;
	SR = NULL;
	waitingList = NULL;
	sNum = atoi(argv[1]);
	mNum = atoi(argv[2]);
	Rnum = atoi(argv[3]);
	Size = atoi(argv[4]);
	cout << 1<< endl;
	for(int i =1; i<=sNum ; i++){ // put into source list
		Source* newsource = new Source();
		newsource->setSourceID(i);
		newsource->setPackList(NULL);
		newsource->setNextSource(NULL);
		newsource->enqueue(&S);

	}
	for(int i =sNum+1;i<=mNum+sNum;i++){ // put into mule list
		Mules* newmule = new Mules();
		newmule->setMuleID(i);
		newmule->setPackList(NULL);
		newmule->setNextMule(NULL);
		newmule->enqueue(&M);
	}
	for(int i =mNum+sNum+1;i<=Rnum+mNum+sNum;i++){ // send to receievr list
		Receiver* newreceiver = new Receiver();
		newreceiver->setReceiverID(i);
		newreceiver->setListOfPacket(NULL);
		newreceiver->setNextReceiver(NULL);
		newreceiver->enqueue(&R);
	}
	int count =0;
	for(int i=0; i<sNum; i++){
		scanf("%d",&sourceID);
		scanf("%d",&arrival_time);
		scanf("%d",&packet);
		count += packet;
		scanf("%d",&packetsize);
		scanf("%d",&Sr_size);

	  for(int i=0; i<Sr_size;i++){ //insert things into waiting list
		  Lists* P = new Lists();
		  scanf("%d",&Sr);
		  P->setnode(Sr);
		  P->setNodePtr(NULL);
		  P->insert(&L);

	  }
	  for(int i =0; i<packet; i++){
		  Packet* a = new Packet();
		  a->setEventPtr(NULL);
		  a->setPacket_ID(i+1);
		  a->setSR_size(Sr_size);
		  a->setSourceList(L);
		  a->setfinal(0);
		  a->setpropagation(0);
		  a->setarr_time(arrival_time);
		  a->setranmission(packetsize);



		  Packet* K = S->findSourceByID(sourceID)->getPackList();

		  a->enqueue(&K);
		  S->findSourceByID(sourceID)->setPackList(K);
		  cout <<S->findSourceByID(sourceID)->getPackList()->getSourceList()->getnode() << endl;
	  }
	}
	Manet(&S,&R,&M,&waitingList,Size,count); // call helper function
	cout << S->findSourceByID(3)->getpos().getx();
	return 0;
}
