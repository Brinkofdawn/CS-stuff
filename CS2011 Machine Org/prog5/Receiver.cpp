#include "Receiver.h"
#include <cstdio>
#include <cstdlib> 


//Arun Donti 
void Receiver::enqueue(Receiver** topPtr){
	 Receiver *newPtr= new Receiver;//pointer to a new node
						Receiver *previousPtr; // point to previous node
						Receiver *currentPtr; // point to current node


						if(newPtr!=NULL)// if there is no nodes add to top of list
						{
						newPtr->ReceiverID=this->ReceiverID;
						newPtr->nextReceiver= NULL;
	                    newPtr->LOPacketfromSource =this->LOPacketfromSource;
	                    newPtr->pos = this->pos;
						previousPtr=NULL;
						currentPtr= *topPtr;
						//loop to end of list
							while(currentPtr != NULL){
							previousPtr=currentPtr;
							currentPtr= currentPtr->nextReceiver;
							}


						if(previousPtr == NULL){ // insert at end of list
						newPtr->nextReceiver = *topPtr;
						*topPtr = newPtr;
						}

						else{// insert between previousPtr and currentPtr
							previousPtr->nextReceiver=newPtr;
							newPtr->nextReceiver=currentPtr;
				}
				}
				}
//Arun Donti 
void Receiver::dequeue(Receiver** topPtr){ // remove one from the list of Receievers
     *topPtr = (*topPtr)->nextReceiver;
}
//Arun Donti 
int Receiver::allsize(Receiver **top) // calculate the size of the packet list in all the receivers
	{
		int count;
		count=0;
		Receiver *newPtr= new Receiver;//pointer to a new node
		Receiver *previousPtr; // point to previous node
		Receiver *currentPtr; // point to current node

		previousPtr=NULL;
		currentPtr= *top;

	while(currentPtr != NULL)
	{
		previousPtr=currentPtr;
		count+=currentPtr->size();
		currentPtr= currentPtr->nextReceiver;


	}

	return count;

	}
	//Arun Donti 
int Receiver::specificsize(int s) // returns number of packets from specific source node
{
	int count;
	count=0;

		Packet *previousPtr; // point to previous node
		Packet *currentPtr; // point to current node
		previousPtr=NULL;
		currentPtr=this->LOPacketfromSource;
		//loop to end of list
			while(currentPtr != NULL)
			{
			previousPtr=currentPtr;
			currentPtr= currentPtr->getEventPtr();
			if (currentPtr->getsourceid()==s)// increment only if the source ids match
			{
				count++;
			}

			}
		return count;

}

//Arun Donti 
int Receiver::size() // returns size of node
{
	int count;
	count=0;

		Packet *previousPtr; // point to previous node
		Packet *currentPtr; // point to current node
		previousPtr=NULL;
		currentPtr=this->LOPacketfromSource;
		//loop to end of list
			while(currentPtr != NULL){
			previousPtr=currentPtr;
			currentPtr= currentPtr->getEventPtr();
			count++;

			}
		return count;

}
//Arun Donti 
int Receiver::specifictotaldelay(int s) // returns to total delay total from a specific source
	{
		int count;
		count=0;

		Packet *previousPtr; // point to previous node
		Packet *currentPtr; // point to current node
		previousPtr=NULL;
		currentPtr=this->LOPacketfromSource;
		//loop to end of list
			while(currentPtr != NULL)
			{
			previousPtr=currentPtr;
			currentPtr= currentPtr->getEventPtr();



			if (currentPtr->getsourceid()==s)
			{
			count+=currentPtr->getfinal()-(currentPtr->getarr_time()+currentPtr->getsize());
			}

			}

		return count;





	}
//Arun Donti 
int Receiver::totaldelay() // returns the otal delay of all packets from all sources
	{
		int count;
		count=0;

		Packet *previousPtr; // point to previous node
		Packet *currentPtr; // point to current node
		previousPtr=NULL;
		currentPtr=this->LOPacketfromSource;
		//loop to end of list
			while(currentPtr != NULL)
			{
			previousPtr=currentPtr;
			currentPtr= currentPtr->getEventPtr();
			count+=currentPtr->getfinal()-(currentPtr->getarr_time()+currentPtr->getsize());

			}

		return count;





	}

	//Thinh Ly
void Receiver::sendPacketToReceiver(Packet** waitingList,int clock){ // send  apacket to the receiver
	Packet* currentPtr = new Packet();
	Receiver* Re = new Receiver();

	currentPtr = *waitingList;
	if(*waitingList!= NULL){
		while (currentPtr != NULL){
			if(currentPtr->getpropagation() == 0 && currentPtr->getSourceList()->getNodePtr()== NULL){
			Re = this->findReceiverByID(currentPtr->getSourceList()->getnode());
			currentPtr->setfinal(clock);
			currentPtr->enqueue(&Re->LOPacketfromSource);
			currentPtr->dequeue(waitingList);
			currentPtr = currentPtr->getEventPtr();
		}
			else currentPtr = currentPtr->getEventPtr();
	}
}
}

//Thinh Ly
Receiver* Receiver::findReceiverByID(int ID){// finds the correct receiver by the id of the reciever
	Receiver* currentPtr;
	currentPtr = this;
if(this == NULL) return NULL;
else{
	while(currentPtr != NULL){
		if (currentPtr->ReceiverID == ID){
			return currentPtr;
			break;
				}
		else currentPtr = currentPtr->nextReceiver;
	}
	return NULL;
}
}
position Receiver::getpos(){
	return this->pos;
}
int Receiver::getReceiverID(){
	return this->ReceiverID;
}
void Receiver::setReceiverID(int R){
	this->ReceiverID = R;
}
Packet* Receiver::getListOfPacket(){
	return this->LOPacketfromSource;
}
void Receiver::setListOfPacket(Packet* L){
	this->LOPacketfromSource = L;
}
void Receiver::setNextReceiver(Receiver* next){
	this->nextReceiver = next;
}
Receiver* Receiver::getNextReceiver(){
	return this->nextReceiver;
}

//Thinh Ly
bool Receiver::check(Receiver* R){
	bool A;
		Receiver* curPtr;
		A = false;
		if (R == NULL) return false;
		else {
			curPtr = R;
			while (curPtr != NULL){
				if (this->pos.equalpos(curPtr->getpos()) && this->ReceiverID != curPtr->getReceiverID()){
					A = true;
					break;
				}
				else {
					curPtr = curPtr->nextReceiver;
					}
			}
			}
		return A;
}

//Thinh Ly
void Receiver::updatePos(int Size){ // update the position fo the receievr
	this->pos.position3(Size);
}

//Thinh Ly
void Receiver::initialize(int Size){// initializes the receiver
	Receiver* curPtr;
	bool A;
	if (this != NULL){
		curPtr = this;
	while(curPtr != NULL){
		curPtr->updatePos(Size);
		A = curPtr->check(this);
	 while(A == true){
		 curPtr->updatePos(Size);
		 A = curPtr->check(this);
		 }
	    curPtr = curPtr->getNextReceiver();
	}
}
}