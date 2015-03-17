//Arun Donti

class receiver
{
public:
	receiver();
	receiver(packet *list, position pos, receiver *next);
	~receiver();

packet *list;
position pos;
receiver *next;
	/* data */
};