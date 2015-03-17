//Arun Donti

sources::sources()
{

} 


sources::sources(int ID, position pos, packet *queue, sources *next)
{
	this->ID=ID;
	this->position=pos;
	this->queue=queue;
	this->next=next;
} 


void sources::addto(sources **top) // adds an sources to the back of a linked lisr
{

		sources *newPtr= new sources;//pointer to a new node
		sources *previousPtr; // point to previous node
		sources *currentPtr; // point to current node


		if(newPtr!=NULL)// if there is no nodes add to top of sources
		{
		newPtr->ID=this->ID;
		newPtr->position=this->position;
		newPtr->queue=this->queue;
		newPtr->next=this->next;	
		newPtr->next=NULL;// no linking to another sources

		previousPtr=NULL;
		currentPtr= *top;
		//loop to end of sources
			while(currentPtr != NULL){
			previousPtr=currentPtr;
			currentPtr= currentPtr->next;
			}


		if(previousPtr == NULL){ // insert at end of sources
		newPtr->next = *top;
		*top = newPtr;
		}
		
		else{// insert between previousPtr and currentPtr
			previousPtr->next=newPtr;
			newPtr->next=currentPtr;
	
		}
		

		}
}