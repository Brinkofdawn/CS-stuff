
#ifndef PACKET_H
#define PACKET_H
#include "Lists.h"

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
#endif
