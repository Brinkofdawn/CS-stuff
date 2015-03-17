#ifndef SOURCE_H
#define SOURCE_H
#include "Packet.h"
#include "position.h"
#include "Mules.h"

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
 #endif