//Arun Donti 

class list
{
public:
	list();
	list(int number, list *next);
	void addto(list **top);
	~list();

	int number;
	list *next;
};