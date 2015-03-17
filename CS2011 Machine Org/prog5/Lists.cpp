#include "Lists.h"
#include <cstdio>
#include <cstdlib>

//Arun Donti whole file

void Lists::insert(Lists** topPtr){ // insert a number into the list of id  numbers thatt packet still needs to travel to.
                Lists *newPtr= new Lists;//pointer to a new node
				Lists *previousPtr; // point to previous node
				Lists *currentPtr; // point to current node


				if(newPtr!=NULL)// if there is no nodes add to top of list
				{
				newPtr->node=this->node;
				newPtr->nodePtr= NULL;

				previousPtr=NULL;
				currentPtr= *topPtr;
				//loop to end of list
					while(currentPtr != NULL){
					previousPtr=currentPtr;
					currentPtr= currentPtr->nodePtr;
					}


				if(previousPtr == NULL){ // insert at end of list
				newPtr->nodePtr = *topPtr;
				*topPtr = newPtr;
				}

				else{// insert between previousPtr and currentPtr
					previousPtr->nodePtr=newPtr;
					newPtr->nodePtr=currentPtr;
		}
		}
		}

void Lists::nextNode(Lists** topPtr){
	*topPtr = (*topPtr)->nodePtr;
}
int Lists::getnode(){
	return this->node;
}
void Lists::setnode(int S){
	this->node = S;
}
Lists* Lists::getNodePtr(){
	return this->nodePtr;
}
void Lists::setNodePtr(Lists* L){
	this->nodePtr = L;
}