//============================================================================
// Name        : Program5.cpp
// Author      : Thinh Ly
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
enum direction{NotMove,EAST, WEST,NORTH, SOUTH};

class Lists{
public:
	void insert(Lists** topPtr);
	void nextNode(Lists** topPtr);
	int getnode();
	void setnode(int S);
	Lists* getNodePtr();
	void setNodePtr(Lists* L);
private:
	int node;
	Lists* nodePtr;
};
void Lists::insert(Lists** topPtr){
                Lists *newPtr= new Lists;//pointer to a new node
				Lists *previousPtr; // point to previous node
				Lists *currentPtr; // point to current node


				if(newPtr!=NULL)// if there is no nodes add to top of list
				{
				newPtr->node=this->node;
				newPtr->nodePtr= NULL;

				previousPtr=NULL;
				currentPtr= *topPtr;
				//loop to end of list
					while(currentPtr != NULL){
					previousPtr=currentPtr;
					currentPtr= currentPtr->nodePtr;
					}


				if(previousPtr == NULL){ // insert at end of list
				newPtr->nodePtr = *topPtr;
				*topPtr = newPtr;
				}

				else{// insert between previousPtr and currentPtr
					previousPtr->nodePtr=newPtr;
					newPtr->nodePtr=currentPtr;
		}
		}
		}

void Lists::nextNode(Lists** topPtr){
	*topPtr = (*topPtr)->nodePtr;
}
int Lists::getnode(){
	return this->node;
}
void Lists::setnode(int S){
	this->node = S;
}
Lists* Lists::getNodePtr(){
	return this->nodePtr;
}
void Lists::setNodePtr(Lists* L){
	this->nodePtr = L;
}
class Packet{
public:
	void enqueue(Packet** topPtr);
	void dequeue(Packet** topPtr);
	int getarr_time();
	void setarr_time(int A);
	int getpacket_id();
	void setpacket_id(int P);
	int getsize();
	void setsize(int S);
	int getsourceid();
	void setsourceid(int SI);
	int getSR_size();
	void setSR_size(int SR);
	Lists* getSourceList();
	void setSourceList(Lists* L);
	Packet* getEventPtr();
	void setEventPtr(Packet* P);
	void updateSourceList();
	Lists* getTimeList();
	void setTimeList(Lists* T);
	void updateTimeList(int N);
	int getPacket_ID();
	void setPacket_ID(int ID);
	int getranmission();
	void setranmission(int time);
	int getpropagation();
	void setpropagation(int time);
	void updatepropagationtime();
    void setfinal(int time);
	int getfinal();
private:
	int final;
	int Packet_ID;
	int Source_id;
	int arrival_time;
	int size;
	int SR_size;
	Lists* sourcelist;
	Lists* timelist;
	Packet *eventPtr;
	int packet_id;
	int transmission;
	int propagation;
};
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
void Packet::updatepropagationtime(){
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
void Packet::updateTimeList(int N){
	Lists* L = new Lists();
	L->setnode(N);
	L->setNodePtr(NULL);
	L->insert(&this->timelist);
}
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

void Packet::dequeue(Packet** topPtr){
     *topPtr = (*topPtr)->eventPtr;
}

class position{
public :
	int getx();
	int gety();
	int getdirection();
	void position1(int Size);
	void position2(int Size);
	void position3(int Size);
	bool equalpos(position Pos);
	float distance(position Pos);
	void movingPos(int Size);
private :
	int x;
	int y;
	int direction;
};
void position::position1(int Size){
	srand(time(NULL));
	this->x = rand() % (Size-1) + 1;
	this->y = rand() % Size;
	this->direction = rand() % 4 +1;
}
void position::position2(int Size){
	srand(time(NULL));
	this->x = 0;
	this->y = rand() % Size;
	this->direction = 0;
}
void position::position3(int Size){
	srand(time(NULL));
    this->x = Size-1;
    this->y = rand() % Size;
	this->direction =0;
}
int position::getx(){
	return this->x;
}
int position::gety(){
	return this->y;
}
int position::getdirection(){
	return this->direction;
}
bool position::equalpos(position Pos){
	return this->x == Pos.getx() && this->y == Pos.gety();
}
float position::distance(position Pos){
	float x;
	float y;
	float results;
	x = this->x - Pos.getx();
	y = this->y - Pos.gety();
	results = sqrt(x*x+y*y);
	return results;
}
void position::movingPos(int Size){
	int dir;
	dir = this->direction;
	switch(dir){
	case NotMove:
		break;
	case EAST:
		if (this->x < Size-1){
			this->x = this->x +1;
		}
		else {
			this->direction = this->direction + 1;
			this->x = this->x-1;
		}
		break;
	case WEST:
		if (this->x > 1){
			this->x = this->x -1;
		}
		else {
			this->direction = this->direction -1;
			this->x = this->x +1;
		}
		break;
	case NORTH:
		if (this->y > 1){
			this->y = this->y -1;
		}
		else {
			this->direction = this->direction +1;
			this->y = this->y +1;
		}
		break;
	case SOUTH:
		if (this->y < Size-1){
			this->y = this->y +1;
		}
		else {
			this->direction = this->direction -1;
			this->y = this->y -1;
		}
		break;
		}
}
class Receiver{
private:
	int ReceiverID;
	position pos;
    Packet* LOPacketfromSource;
    Receiver* nextReceiver;
public:
    void enqueue(Receiver** R);
    void dequeue(Receiver** R);
    int size();
    int specifictotaldelay(int s);
    int totaldelay();
    int getReceiverID();
    void setReceiverID(int R);
    position getpos();
    Packet* getListOfPacket();
    void setListOfPacket(Packet* P);
    Receiver* getNextReceiver();
    void setNextReceiver(Receiver* next);
    bool check(Receiver* R);
    void initialize(int Size);
    void updatePos(int Size);
    Receiver* findReceiverByID(int ID);
    void sendPacketToReceiver(Packet** P,int clock);
    int specificsize(int s);
    int allsize(Receiver** top);
};
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
void Receiver::dequeue(Receiver** topPtr){
     *topPtr = (*topPtr)->nextReceiver;
}
int Receiver::allsize(Receiver **top)
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

int Receiver::specifictotaldelay(int s)
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

int Receiver::totaldelay()
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
void Receiver::sendPacketToReceiver(Packet** waitingList,int clock){
	Packet* currentPtr = new Packet();
	Receiver* Re = new Receiver();

	currentPtr = *waitingList;
	if(*waitingList!= NULL){
		while (currentPtr != NULL){
			if(currentPtr->getpropagation() == 0 && currentPtr->getSourceList()== NULL){
			Re = this->findReceiverByID(currentPtr->getSourceList()->getnode());
			currentPtr->setfinal(clock);
			currentPtr->enqueue(&Re->LOPacketfromSource);
			currentPtr->dequeue(waitingList);
			cout << "the packet number" << currentPtr->getPacket_ID()<< "from" << currentPtr->getsourceid()<< "arrived at" << Re->ReceiverID << "at the time"<< clock <<endl;
			currentPtr = currentPtr->getEventPtr();
		}
			else currentPtr = currentPtr->getEventPtr();
	}
}
}
Receiver* Receiver::findReceiverByID(int ID){
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
void Receiver::updatePos(int Size){
	this->pos.position3(Size);
}
void Receiver::initialize(int Size){
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

class Mules{
private:
	int MulesID;
	position pos;
	Packet* packlist;
	Mules* nextmule;
public:
	void enqueue(Mules** topPtr);
	void dequeue(Mules** topPtr);
	int getMuleID();
	void setMuleID(int M);
	position getpos();
	void updatePos(int Size);
	Packet* getPackList();
	void setPackList(Packet* E);
	Mules* getNextMule();
	void setNextMule(Mules* M);
	int distance(Mules* M);
	int distance(Receiver* R);
	int checkforcollision(Mules* M);
	bool check(Mules* M);
	void initialize(int Size);
    void MovingMules(int Size);
    Mules* findMulesbyID(int ID);
    void sendPacketToMules(Packet** P, int clock);
    void sendPacketToWaitingList(Packet** waitingList, Receiver** waitlist);
    void updatetransmissiontime();
};
void Mules::updatetransmissiontime(){
	Mules* currentPtr = new Mules();
	currentPtr = this;
	if(this != NULL){
		while(currentPtr != NULL){
			if(currentPtr->packlist != NULL){
		currentPtr->packlist->setranmission(currentPtr->packlist->getranmission()-1);
			}
		currentPtr= currentPtr->nextmule;
	}
}
}
void Mules::sendPacketToWaitingList(Packet** waitingList, Receiver** R){
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

void Mules::sendPacketToMules(Packet** waitingList,int clock){
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

                 cout << "the packet number" << currentPtr->getPacket_ID()<< "from" << currentPtr->getsourceid()<< "arrived at" << Mule->MulesID << "at the time"<< clock <<endl;
                 currentPtr = currentPtr->getEventPtr();
			}
			else currentPtr = currentPtr->getEventPtr();
		}
	}
}

Mules* Mules::findMulesbyID(int ID){
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
int Mules::distance(Mules* M){
	float results;
	int time;
	results = this->pos.distance(M->getpos());
	time =log2(results);

	return time;
}
int Mules::distance(Receiver* R){
	float results;
	int time;
	results = this->pos.distance(R->getpos());
	time = log2(results);
	return time;
}
bool Mules::check(Mules* M){
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
int Mules::checkforcollision(Mules* M){
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
void Mules::updatePos(int Size){
	this->pos.position1(Size);
}
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
void Mules::MovingMules(int Size){
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
void Mules::dequeue(Mules** topPtr){
     *topPtr = (*topPtr)->nextmule;
}
class Source{
private:
	int sourceID;
	position pos;
    Packet* packlist;
    Source* nextsource;
public:
    void enqueue(Source** topPtr);
    void dequeue(Source** topPtr);
    int getSourceID();
    void setSourceID(int S);
    position getpos();
    void updatePos(int Size);
    Packet* getPackList();
    void setPackList(Packet* P);
    Source* getNextSource();
    void setNextSource(Source* S);
    int distance(Mules* M);
    bool check(Source* S);
    void initialize(int Size);
    Source* findSourceByID(int ID);
    void sendPacketToWaitingList(Packet** topPtr, Mules** M);
    void updatetransmissiontime();
 };
void Source::updatetransmissiontime(){
	Source* currentPtr = new Source();
		currentPtr = this;
		if(this != NULL){
			while(currentPtr != NULL){
				if(currentPtr->packlist != NULL){
					currentPtr->packlist->setranmission(currentPtr->packlist->getranmission()-1);
						}

			currentPtr= currentPtr->nextsource;
		}
	}
	}

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
void Source::dequeue(Source** topPtr){
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
int Source::distance(Mules* M){
	float results;
	int time;
	results = this->pos.distance(M->getpos());
	time = log2(results);
	return results;
}
bool Source::check(Source* S){
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
void Source::initialize(int Size){
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
Source* Source::findSourceByID(int ID){
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
void Source::sendPacketToWaitingList(Packet** waitingList,Mules** M){
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
class Board
{
public:
	Board(Receiver *R, Source *S, Mules *M);
	void makeBoard(int Size);
private:
	Receiver *R;
	Source *S;
	Mules *M;
	/* data */
};

Board::Board(Receiver *R, Source *S, Mules *M)
{
	this->R=R;
	this->S=S;
	this->M=M;
}
void Board::makeBoard(int Size){
	int S = Size;
	int board[S][S];
	for (int i = 0; i<Size; i++){
		for(int j= 0; j<Size; j++){
			board[i][j] = 0;
		}
	}
	Receiver* Re = new Receiver();
	Source* So = new Source();
	Mules* Mu = new Mules();
	Re = this->R;
	So = this->S;
	Mu = this->M;
	while(Re != NULL){
		board[Re->getpos().getx()][Re->getpos().gety()] = Re->getReceiverID();
		Re = Re->getNextReceiver();
	}
	while(So!= NULL){
		board[So->getpos().getx()][So->getpos().gety()] = So->getSourceID();
				So = So->getNextSource();
	}
	while(Mu!=NULL){
		board[Mu->getpos().getx()][Mu->getpos().gety()] = Mu->getMuleID();
		Mu = Mu->getNextMule();
	}
	 // for-loop, using to print out the field
		for (int i=-1; i<=Size; i++){
	                 for(int j=0;j<Size; j++){
			    	   // using to print out the top and bottom border of the field
	                	 if(i==-1 || i==(Size)){
			    		   printf("___"); // using character '_' to print out the up and bottom border
			    		}
			    	   else{ if(j==0){
			    		   printf("\n|%3d", board[j][i]); // print out the left border of the field
			    		   }
			    	   else { if(j== Size-1){
			    		   if (i!= Size-1){
			    		   printf("%3d|", board[j][i]);// print out the right border of the field
			    		   }
			    		   else printf("%3d|\n", board[j][i]); // fill in the number to the field
			    	   }

			    	   else printf("%3d" ,board[j][i]);
			    		   }
			}
			       }

		   }
				printf("\n");
	}


void Manet(Source** S, Receiver** R, Mules** M, Packet** waitinglist, int Size, int total){
	int clock;
	Board* B;
	B = new Board(*R, *S, *M);
	clock =0 ;
	(*R)->initialize(Size);
		(*M)->initialize(Size);
		(*S)->initialize(Size);
	     B->makeBoard(Size);
while((*R)->allsize(R) < total){

    (*M)->sendPacketToWaitingList(waitinglist, R);

    (*S)->sendPacketToWaitingList(waitinglist,M);

    // need a function to send to waiting list for receiver
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
	for(int i =1; i<=sNum ; i++){
		Source* newsource = new Source();
		newsource->setSourceID(i);
		newsource->setPackList(NULL);
		newsource->setNextSource(NULL);
		newsource->enqueue(&S);

	}
	for(int i =sNum+1;i<=mNum+sNum;i++){
		Mules* newmule = new Mules();
		newmule->setMuleID(i);
		newmule->setPackList(NULL);
		newmule->setNextMule(NULL);
		newmule->enqueue(&M);
	}
	for(int i =mNum+sNum+1;i<=Rnum+mNum+sNum;i++){
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

	  for(int i=0; i<Sr_size;i++){
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
	Manet(&S,&R,&M,&waitingList,Size,count);
	cout << S->findSourceByID(3)->getpos().getx();
	return 0;
}
