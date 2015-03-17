#include <string>
using namespace std;

class event
{
public:
	event();
	event(string source,int pid,int arrival, event *eventPtr) ;
	int size(event **top);
	void addto(event **top);
	event get_nextevent(event **sPtr); 
	string source;// specify which starting source it came from
	int pid; // give the packet and id number
	int arrival; // stores propagation time and arrival time
	event *eventPtr;




	/* data */
};