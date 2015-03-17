
#ifndef MULES_H
#define MULES_H
#include "position.h"
#include "Packet.h"
#include "Receiver.h"

// Thinh Ly

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

#endif