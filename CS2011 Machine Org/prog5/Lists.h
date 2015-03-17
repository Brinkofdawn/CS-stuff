#ifndef LISTS_H
#define LISTS_H



class Lists{
public:
	void insert(Lists** topPtr);
	void nextNode(Lists** topPtr);
	int getnode();
	void setnode(int S);
	Lists* getNodePtr();
	void setNodePtr(Lists* L);
private:
	int node;
	Lists* nodePtr;
};

#endif