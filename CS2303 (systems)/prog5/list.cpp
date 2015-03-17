//Arun Donti 

list::list()
{

}

list::list(int number, list *next)
{
	this->number=number;
	this->next=next;
}

void list::addto(list **top) // adds an list to the back of a linked lisr
{

		list *newPtr= new list;//pointer to a new node
		list *previousPtr; // point to previous node
		list *currentPtr; // point to current node


		if(newPtr!=NULL)// if there is no nodes add to top of list
		{
		newPtr->number=this;	
		newPtr->next=NULL;// no linking to another list

		previousPtr=NULL;
		currentPtr= *top;
		//loop to end of list
			while(currentPtr != NULL){
			previousPtr=currentPtr;
			currentPtr= currentPtr->next;
			}


		if(previousPtr == NULL){ // insert at end of list
		newPtr->next = *top;
		*top = newPtr;
		}
		
		else{// insert between previousPtr and currentPtr
			previousPtr->next=newPtr;
			newPtr->next=currentPtr;
	
		}
		

		}
}