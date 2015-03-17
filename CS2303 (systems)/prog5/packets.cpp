// Arun Donti


packets::packets()
{


}

packets::packets(int sourceID,int arrival,int packetnumber,int psize,int srsize,list *ID, packets *next)
{
	this->sourceID=sourceID;
	this->arrival=arrival;
	this->packetnumber=packetnumber;
	this->psize=psize;
	this->srsize=srsize;
	this->ID=ID;
	this->next=next;
}

void packets::addto(packets **top) // adds an packets to the back of a linked list
{

		packets *newPtr= new packets;//pointer to a new node
		packets *previousPtr; // point to previous node
		packets *currentPtr; // point to current node


		if(newPtr!=NULL)// if there is no nodes add to top of list
		{
		newPtr->sourceID=this->sourceID;	
		newPtr->arrival= this->arrival;
		newPtr->packetnumber=this->packetnumber;
		newPtr->psize=this->psize;
		newPtr->srsize=this->srsize;
		newPtr->ID=this->ID;
		newPtr->next=NULL;// no linking to another packets

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