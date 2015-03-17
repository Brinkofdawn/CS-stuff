//Arun Donti 

class packets
{
public:
	packets(int sourceID,int arrival,int packetnumber,int psize,int srsize,list *ID,vpackets *next);
	~packets();

	int sourceID;
	int arrival;
	int packetnumber;
	int psize;
	int srsize;
	list *ID;
	packets *next; 

};