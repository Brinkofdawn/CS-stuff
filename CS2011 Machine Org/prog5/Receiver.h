
#ifndef RECEIVER_H
#define RECEIVER_H
#include "position.h"
#include "Packet.h"
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
#endif