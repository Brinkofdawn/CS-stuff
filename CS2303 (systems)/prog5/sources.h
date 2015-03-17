//Arun Donti

class sources
{
public:
	sources();
	sources(int ID, position pos, packet *queue, sources *next);
	~sources();

	int ID;
	position pos;
	packet *queue;
	sources *next;

	/* data */
};