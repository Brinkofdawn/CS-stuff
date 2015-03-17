#include "Packet.h"
#include <cstdio>
#include <cstdlib>

void Packet::setsourceid(int SI){
	this->Source_id = SI;
}
void Packet::setfinal(int time){
	this->final = time;
}
int Packet::getsourceid(){
	return this->Source_id;
}
int Packet::getfinal(){
	return this->final;
}
void Packet::updatepropagationtime(){// decerement the propogation time of the packet by 1 every time the program calls itself
	Packet* currentPtr;
	currentPtr = this;
	if(this!= NULL){
		while(currentPtr != NULL){
			currentPtr->propagation = currentPtr->propagation -1;
			currentPtr = currentPtr->eventPtr;
		}
	}
}
int Packet::getPacket_ID(){
	return this->Packet_ID;
}
int Packet::getarr_time(){
	return this->arrival_time;
}
int Packet::getpropagation(){
	return this->propagation;
}
void Packet::setpropagation(int time){
	this->propagation = time;
}
int Packet::getranmission(){
	return this->transmission;
}
void Packet::setranmission(int time){
	this->transmission = time;
}
void Packet::setPacket_ID(int ID){
	this->Packet_ID = ID;
}
void Packet::setTimeList(Lists* T){
	this->timelist = T;
}

// Thinh Ly

void Packet::updateTimeList(int N){// updates the list of which mules and receivers the pakcet needs to go to next
	Lists* L = new Lists();
	L->setnode(N);
	L->setNodePtr(NULL);
	L->insert(&this->timelist);
}

// Thinh Ly

void Packet::updateSourceList(){
	this->sourcelist = this->sourcelist->getNodePtr();
}


void Packet::setarr_time(int A){
	this->arrival_time = A;
}
int Packet::getsize(){
	return this->size;
}
Packet* Packet::getEventPtr(){
	return this->eventPtr;
}
Lists* Packet::getSourceList(){
	return this->sourcelist;
}
void Packet::setsize(int S){
	this->size = S;
}
void Packet::setSR_size(int SR){
	this->SR_size = SR;
}

void Packet::setSourceList(Lists* L){
	this->sourcelist = L;
}
void Packet::setEventPtr(Packet *P){
	this->eventPtr = P;
}

// Arun Donti
void Packet::enqueue(Packet **topPtr) // adds an Packet to the back of a linked list
{

		Packet *newPtr= new Packet;//pointer to a new node
		Packet *previousPtr; // point to previous node
		Packet *currentPtr; // point to current node


		if(newPtr!=NULL)// if there is no nodes add to top of list
		{
		newPtr->Source_id=this->Source_id;
		newPtr->arrival_time= this->arrival_time;
		newPtr->size=this->size;
		newPtr->SR_size=this->SR_size;
		newPtr->sourcelist=this->sourcelist;
		newPtr->eventPtr=NULL;// no linking to another Packet
        newPtr->Packet_ID = this->Packet_ID;
        newPtr->timelist = this->timelist;
        newPtr->transmission = this->transmission;
		previousPtr=NULL;
		currentPtr= *topPtr;
		//loop to end of list
			while(currentPtr != NULL){
			previousPtr=currentPtr;
			currentPtr= currentPtr->eventPtr;
			}


		if(previousPtr == NULL){ // insert at end of list
		newPtr->eventPtr = *topPtr;
		*topPtr = newPtr;
		}

		else{// insert between previousPtr and currentPtr
			previousPtr->eventPtr=newPtr;
			newPtr->eventPtr=currentPtr;
}
}
}

//Arun Donti
void Packet::dequeue(Packet** topPtr){// takes the top packet off the list of packets
     *topPtr = (*topPtr)->eventPtr;
}