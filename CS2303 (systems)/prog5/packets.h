//Arun Donti 

class packets
{
public:
	packets();
	packets(int sourceID,int arrival,int packetnumber,int psize,int srsize,list *ID, packets *next);
	void addto(packets **top); 
	~packets();

	int sourceID;
	int arrival;
	int packetnumber;
	int psize;
	int srsize;
	list *ID;
	packets *next; 

};