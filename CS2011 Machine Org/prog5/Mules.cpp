#include "Mules.h"
#include <cstdio>
#include <cstdlib> 
#include <cmath>
#include <iostream>
using namespace std;

// Thinh Ly
void Mules::updatetransmissiontime(){ // update the transmission times of all the packets 
	Mules* currentPtr = new Mules();
	currentPtr = this;
	if(this != NULL){
		while(currentPtr != NULL){
			if(currentPtr->packlist !=NULL){
				currentPtr->packlist->setranmission(currentPtr->packlist->getranmission()-1);}

		currentPtr= currentPtr->nextmule;
	}
}
}
// Thinh Ly

void Mules::sendPacketToWaitingList(Packet** waitingList, Receiver** R){ // send the packet to waiting list for propogation time
     Mules* currentPtr;
     Packet* packetPtr;
     currentPtr = this;
     if(this != NULL){
    	 while(currentPtr != NULL){
    		 if(currentPtr->packlist != NULL){
    	 if(currentPtr->getPackList()->getranmission() == 0){
            if(currentPtr->packlist->getSourceList()->getNodePtr()->getNodePtr() != NULL){
    		 packetPtr = currentPtr->packlist;
               packetPtr->setpropagation(currentPtr->distance(this->findMulesbyID(currentPtr->packlist->getSourceList()->getnode())));
               packetPtr->setranmission(packetPtr->getsize());
               packetPtr->enqueue(waitingList);
               packetPtr->setSourceList(packetPtr->getSourceList()->getNodePtr());
               currentPtr->getPackList()->dequeue(&currentPtr->packlist);
               currentPtr = currentPtr->nextmule;
    	 }
            else {
            	 packetPtr = currentPtr->packlist;
            	 packetPtr->setpropagation(currentPtr->distance((*R)->findReceiverByID(currentPtr->packlist->getSourceList()->getnode())));
            	 packetPtr->setranmission(packetPtr->getsize());
            	 packetPtr->enqueue(waitingList);
            	 packetPtr->setSourceList(packetPtr->getSourceList()->getNodePtr());
            	 currentPtr->getPackList()->dequeue(&currentPtr->packlist);
            	 currentPtr = currentPtr->nextmule;
            }
    	 }
    	 else currentPtr = currentPtr->nextmule;
     }
    		 else currentPtr = currentPtr->nextmule;
}
     }
}
// Thinh Ly

void Mules::sendPacketToMules(Packet** waitingList,int clock){ // which Mule to send the packet to next
	Packet* currentPtr = new Packet();
	Mules* Mule = new Mules();
	currentPtr = *waitingList;
	if (*waitingList != NULL){
		while (currentPtr != NULL){
			if(currentPtr->getpropagation() == 0 && currentPtr->getSourceList()->getNodePtr()!= NULL){
                 Mule = this->findMulesbyID(currentPtr->getSourceList()->getnode());
                 currentPtr->setpropagation(0);
                 currentPtr->enqueue(&Mule->packlist);
                 currentPtr->dequeue(waitingList);
                 currentPtr = currentPtr->getEventPtr();
                 cout << "the packet number" << currentPtr->getPacket_ID()<< "from" << currentPtr->getsourceid()<< "arrived at" << Mule->MulesID << "at the time"<< clock <<endl;
			}
			else currentPtr = currentPtr->getEventPtr();
		}
	}
}
// Thinh Ly

Mules* Mules::findMulesbyID(int ID){// goes through lists of mule sto find the muspecified mule by id
	Mules* currentPtr;
    currentPtr = this;
   if (this == NULL) return NULL;
   else{
	   while (currentPtr!=NULL){
		   if(currentPtr->MulesID == ID){
			   return currentPtr;
			   break;
		   }
		   else currentPtr = currentPtr->nextmule;
	   }
	   return NULL;
   }
}
int Mules::getMuleID(){
	return this->MulesID;
}
void Mules::setMuleID(int M){
	this->MulesID = M;
}
position Mules::getpos(){
	return this->pos;
}
Packet* Mules::getPackList(){
	return this->packlist;
}
void Mules::setPackList(Packet* E){
	this->packlist = E;
}
Mules* Mules::getNextMule(){
	return this->nextmule;
}
void Mules::setNextMule(Mules* M){
	this->nextmule = M;
}
// Thinh Ly

int Mules::distance(Mules* M){
	float results;
	int time;
	results = this->pos.distance(M->getpos());
	time =log2(results);

	return time;
}
// Thinh Ly

int Mules::distance(Receiver* R){ // calculate the Euclidian distance between mule and reeievr
	float results;
	int time;
	results = this->pos.distance(R->getpos());
	time = log2(results);
	return time;
}
// Thinh Ly

bool Mules::check(Mules* M){ // check if mule is still there
	bool A;
	Mules* curPtr;
	A = false;
	if (M == NULL) return false;
	else {
		curPtr = M;
		while (curPtr != NULL){
			if (this->pos.equalpos(curPtr->getpos()) && this->MulesID != curPtr->getMuleID()){
				A = true;
				break;
			}
			else {
				curPtr = curPtr->nextmule;
				}
		}
		}
	return A;
}
// Thinh Ly

int Mules::checkforcollision(Mules* M){ // check if the mules are going to collide with each other
	bool A;
	int B;
	B=0;
	Mules* curPtr;
	A = false;
	if (M == NULL) return 0;
	else {
		curPtr = M;
		while (curPtr != NULL){
			if (this->pos.equalpos(curPtr->getpos()) && this->MulesID != curPtr->getMuleID()){
				A = true;
				B = curPtr->MulesID;
				break;
			}
			else {
				curPtr = curPtr->nextmule;
				}
		}
		}
	return B;
}
// Thinh Ly

void Mules::updatePos(int Size){ // update the position of the mule on the board
	this->pos.position1(Size);
}
// Thinh Ly

void Mules::initialize(int Size){
	Mules* curPtr;
	bool A;
	if (this != NULL){
		this->updatePos(Size);
		curPtr = this->nextmule;
	while(curPtr != NULL){
		curPtr->updatePos(Size);
		A = curPtr->check(this);
	 while(A == true){
		 curPtr->updatePos(Size);
		 A = curPtr->check(this);
		 }
	    curPtr = curPtr->getNextMule();
	}
}
}
// Thinh Ly

void Mules::MovingMules(int Size){// function for checking alll the factors on the moving mules
   Mules* curPtr;
   bool A;
   curPtr = this;
   while (curPtr!= NULL){
	   curPtr->pos.movingPos(Size);
	   A = curPtr->check(this);
	 while(A== true){
		if(curPtr->checkforcollision(this) < curPtr->MulesID){
              curPtr->pos.movingPos(Size);
		}
		else break;
	 }
	    curPtr = curPtr->nextmule;
   }
}
// Arun Donti
void Mules::enqueue(Mules** topPtr){

	                Mules *newPtr= new Mules;//pointer to a new node
					Mules *previousPtr; // point to previous node
					Mules *currentPtr; // point to current node


					if(newPtr!=NULL)// if there is no nodes add to top of list
					{
					newPtr->MulesID=this->MulesID;
					newPtr->nextmule= NULL;
                    newPtr->packlist =this->packlist;
                    newPtr->pos = this->pos;
					previousPtr=NULL;
					currentPtr= *topPtr;
					//loop to end of list
						while(currentPtr != NULL){
						previousPtr=currentPtr;
						currentPtr= currentPtr->nextmule;
						}


					if(previousPtr == NULL){ // insert at end of list
					newPtr->nextmule = *topPtr;
					*topPtr = newPtr;
					}

					else{// insert between previousPtr and currentPtr
						previousPtr->nextmule=newPtr;
						newPtr->nextmule=currentPtr;
			}
			}
			}
		// Arun Donti
void Mules::dequeue(Mules** topPtr){ // go to the next mule on hte list
     *topPtr = (*topPtr)->nextmule;
}