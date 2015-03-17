#include "Source.h"
#include "Mules.h"
#include <cstdio>
#include <cstdlib> 
#include <cmath>


//Thinh Ly
void Source::updatetransmissiontime(){ // update the transmission time in the packets
	Source* currentPtr = new Source();
		currentPtr = this;
		if(this != NULL){
			while(currentPtr != NULL){
				if(currentPtr->packlist !=NULL){
					currentPtr->packlist->setranmission(currentPtr->packlist->getranmission()-1);}
			currentPtr= currentPtr->nextsource;
		}
	}
	}

//Arun Donti
void Source::enqueue(Source** topPtr){
	                    Source *newPtr= new Source;//pointer to a new node
						Source *previousPtr; // point to previous node
						Source *currentPtr; // point to current node


						if(newPtr!=NULL)// if there is no nodes add to top of list
						{
						newPtr->sourceID=this->sourceID;
						newPtr->nextsource= NULL;
	                    newPtr->packlist =this->packlist;
	                    newPtr->pos = this->pos;
						previousPtr=NULL;
						currentPtr= *topPtr;
						//loop to end of list
							while(currentPtr != NULL){
							previousPtr=currentPtr;
							currentPtr= currentPtr->nextsource;
							}
                        if(previousPtr == NULL){ // insert at end of list
						 newPtr->nextsource = *topPtr;
						 *topPtr = newPtr;
						}

						else{// insert between previousPtr and currentPtr
							previousPtr->nextsource=newPtr;
							newPtr->nextsource=currentPtr;
				}
				}
				}
void Source::dequeue(Source** topPtr){ // take off the first Source in the list
	*topPtr = (*topPtr)->nextsource;
}
int Source::getSourceID(){
	return this->sourceID;
}
void Source::setSourceID(int S){
	this->sourceID = S;
}
position Source::getpos(){
	return this->pos;
}
void Source::updatePos(int Size){
	this->pos.position2(Size);
}
Packet* Source::getPackList(){
	return this->packlist;
}
void Source::setPackList(Packet* P){
	this->packlist = P;
}
Source* Source::getNextSource(){
	return this->nextsource;
}
void Source::setNextSource(Source* S){
	this->nextsource = S;
}

//Arun Donti
int Source::distance(Mules* M){
	float results;
	int time;
	results = this->pos.distance(M->getpos());
	time = log2(results);
	return results;
}
//Thinh Ly
bool Source::check(Source* S){// checking if the sources are there
	bool A;
		Source* curPtr;
		A = false;
		if (S == NULL) return false;
		else {
			curPtr = S;
			while (curPtr != NULL){
				if (this->pos.equalpos(curPtr->getpos()) && this->sourceID != curPtr->getSourceID()){
					A = true;
					break;
				}
				else {
					curPtr = curPtr->nextsource;
					}
			}
			}
		return A;
	}
	//Thinh Ly
void Source::initialize(int Size){// initialize the sources
	Source* curPtr;
		bool A;
		if (this != NULL){
			this->updatePos(Size);
			curPtr = this->nextsource;
		while(curPtr != NULL){
			curPtr->updatePos(Size);
			A = curPtr->check(this);
		 while(A == true){
			 curPtr->updatePos(Size);
			 A = curPtr->check(this);
			 }
		    curPtr = curPtr->getNextSource();
		}
	}
}
//Thinh Ly
Source* Source::findSourceByID(int ID){// goes through the list of sources and fins them by id
	Source* currentPtr;
	currentPtr = this;
	if (this==NULL) return NULL;
	else{
		while(currentPtr != NULL){
			if(currentPtr->sourceID == ID){
				return currentPtr;
				break;
			}
			else currentPtr = currentPtr->nextsource;
		}
		return NULL;
	}
}
//Thinh Ly
void Source::sendPacketToWaitingList(Packet** waitingList,Mules** M){// send the packet to thhe waiting list and then to the next mule
	    Source* currentPtr;
	     Packet* packetPtr;
	     currentPtr = this;
	     if(this != NULL){
	    	 while(currentPtr != NULL){
	    		 if(currentPtr->packlist != NULL){
	    	 if(currentPtr->getPackList()->getranmission() == 0){
	               packetPtr = currentPtr->packlist;
	               packetPtr->setpropagation(currentPtr->distance((*M)->findMulesbyID(currentPtr->packlist->getSourceList()->getnode())));
	               packetPtr->setranmission(packetPtr->getsize());
	               packetPtr->enqueue(waitingList);
	               packetPtr->setSourceList(packetPtr->getSourceList()->getNodePtr());
	               currentPtr->getPackList()->dequeue(&currentPtr->packlist);
	               currentPtr = currentPtr->nextsource;
	    	 }
	    	 else currentPtr = currentPtr->nextsource;
	     }
	    		 else currentPtr = currentPtr->nextsource;
	}
	     }
	}