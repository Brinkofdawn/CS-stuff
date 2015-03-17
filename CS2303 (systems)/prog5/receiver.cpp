//Arun Donti

receiver::receiver()
	{
		
	}

receiver::receiver(packet *list, position pos, receiver *next)
	{
		this->list=list;
		this->pos=pos;
		this->next=next;
	}



void receiver::addto(receiver **top) // adds an receiver to the back of a linked lisr
{

		receiver *newPtr= new receiver;//pointer to a new node
		receiver *previousPtr; // point to previous node
		receiver *currentPtr; // point to current node


		if(newPtr!=NULL)// if there is no nodes add to top of receiver
		{
		newPtr->ID=this->ID;
		newPtr->position=this->position;
		newPtr->queue=this->queue;
		newPtr->next=this->next;	
		newPtr->next=NULL;// no linking to another receiver

		previousPtr=NULL;
		currentPtr= *top;
		//loop to end of receiver
			while(currentPtr != NULL){
			previousPtr=currentPtr;
			currentPtr= currentPtr->next;
			}


		if(previousPtr == NULL){ // insert at end of receiver
		newPtr->next = *top;
		*top = newPtr;
		}
		
		else{// insert between previousPtr and currentPtr
			previousPtr->next=newPtr;
			newPtr->next=currentPtr;
	
		}
		

		}
}

int receiver::size() // returns size of node
{
	int count;
	count=0;

		packet *previousPtr; // point to previous node
		packet *currentPtr; // point to current node
		previousPtr=NULL;
		currentPtr=*(this->list);
		//loop to end of list
			while(currentPtr != NULL){
			previousPtr=currentPtr;
			currentPtr= currentPtr->next;
			count++;

			}
		return count;

}

int receiver::specifictotaldelay(int s)
	{
		int count;
		count=0;

		packet *previousPtr; // point to previous node
		packet *currentPtr; // point to current node
		previousPtr=NULL;
		currentPtr=*(this->list);
		//loop to end of list
			while(currentPtr != NULL)
			{
			previousPtr=currentPtr;
			currentPtr= currentPtr->next;

			

			if (currentPtr->sourceID==s)
			{
			count+=totaltime-(currentPtr->arrival+currentPtr->psize);
			}	

			}
			
		return count;





	}

int receiver::totaldelay()
	{
		int count;
		count=0;

		packet *previousPtr; // point to previous node
		packet *currentPtr; // point to current node
		previousPtr=NULL;
		currentPtr=*(this->list);
		//loop to end of list
			while(currentPtr != NULL){
			previousPtr=currentPtr;
			currentPtr= currentPtr->next;
			count+=totaltime-(currentPtr->arrival+currentPtr->psize);

			}
		return count;





	}


int receiver::specificsize(int s) // returns number of packets from specific source node
{
	int count;
	count=0;

		packet *previousPtr; // point to previous node
		packet *currentPtr; // point to current node
		previousPtr=NULL;
		currentPtr=*(this->list);
		//loop to end of list
			while(currentPtr != NULL)
			{
			previousPtr=currentPtr;
			currentPtr= currentPtr->next;
			if (currentPtr->sourceID==s)// increment only if the source ids match
			{
				count++;
			}

			}
		return count;

}





