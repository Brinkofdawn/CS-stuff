//============================================================================
// Name        : Program4.cpp
// Author      : Thinh Ly, Arun Donti
// Copyright   : Your copyright notice
// Description : Program 4 in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
// Authors: Arun Donti , Thinh Ly


#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;


struct line
{

	int linenum;  // line number
	line* linepointer; // pointer to next line number
 };
typedef struct line Line;
typedef Line* Link;



void insert(int linenum, Link *slinePtr)
{
	Link currentline = new Line();
	Link nextline = new Line();
	nextline->linenum = linenum;
	nextline->linepointer = NULL;
    currentline = *slinePtr;

	if(currentline== NULL) // insert newline if current pointer is NULL
	{
        *slinePtr = nextline;
	}

	else insert(linenum,&(*slinePtr)->linepointer);
	
}
void printlist(Link *slinePtr){
     if (*slinePtr == NULL) printf(" ");
  else { printf("%3d",(*slinePtr)->linenum);
         printlist(&(*slinePtr)->linepointer);
         printf("\n");
}
}
      
struct Tree
{

	string name;
	int amount;
	Link lines;
	Tree* leftpointer;
	Tree* rightpointer;


};
typedef struct Tree TREE;
typedef TREE* TREELink;


void insertTree(TREELink *nodePtr, string name, int amount , int linenum){
    TREELink nNodePtr, temPtr;
    Link L;
    L = new Line();
    L->linenum = linenum;
    L->linepointer = NULL;
    nNodePtr = new TREE();//(TREELink) malloc(sizeof(TREE)); //assigned a address to the new node
    nNodePtr->name = name; // copy information in to the new node
    	   nNodePtr->amount = amount;
    	   nNodePtr->lines = L;
    	   nNodePtr->leftpointer = NULL; // set initial value of the left pointer and right pointer of the node to NULL
    	   nNodePtr->rightpointer= NULL;
// check if there is memory available for the new node
   if(nNodePtr != NULL){
	   // check to see if the tree that will be inserted to is empty or not
   if (*nodePtr == NULL){
	   *nodePtr = nNodePtr; // if empty , the new node will be the first node of the tree
   }
   else {
	   // check to see if there is any repetition of Student ID
	   if(name != (*nodePtr)->name) /* check to see if the new node Student ID is less than the first node student ID*/{

	   if((*nodePtr)->name.compare(nNodePtr->name) >0){
		   if ((*nodePtr)->leftpointer == NULL){
			   (*nodePtr)->leftpointer = nNodePtr;
		   }
		   else {
			    temPtr = (*nodePtr)->leftpointer;
		        insertTree(&temPtr,name, amount, linenum); /*recursive call for the left subtree*/
	   }
   }
   if((*nodePtr)->name.compare(nNodePtr->name)<0)/* check to see if the new node Student ID is greater than the first node student ID*/{
		   if ((*nodePtr)->rightpointer == NULL){
		 			   (*nodePtr)->rightpointer = nNodePtr;
		 		   }
		   else {
			    temPtr = (*nodePtr)->rightpointer;
		        insertTree(&temPtr,name,amount,linenum); // recursive call for the right subtree
	   }
	   }
}
	  else {
       (*nodePtr)->amount++;
       insert(linenum,&(*nodePtr)->lines);
   }
   }
}
   else printf("invalid");
}
string seperateword(string word){ // seperates the line  into words
	int i;
	string k;     
for (i=0; i < word.length(); i++){
    	 if(word.at(i) != ' ' && word.at(i) != ',' && word.at(i) != '.' && word.at(i) != '?' && word.at(i) != '!'){ // create the word if one of these characters are hit
    		k += word.at(i);
    		}
            else break;
    	 }
     return k;
}
int countblank(string word){     
     int i,j;
     for (j=0; j <word.length(); j++){ // count blank spaces
       if(!word.empty()){          
 if (word.at(j) == ' ')
            { i=i+1;
}
}
else break;
}
     return i;
}
void print_tree(TREELink *NodePtr){ // print out the nodes in the tree in order
	TREELink rightPtr;
	TREELink leftPtr;
	if(*NodePtr == NULL){
		printf(" ") ;
	}
	else{
	 rightPtr = (*NodePtr)->rightpointer;
	 leftPtr = (*NodePtr)->leftpointer;
	 print_tree(&leftPtr);
	 printf("%3s , %3d"  ,(*NodePtr)->name.c_str(),  (*NodePtr)->amount);
         printlist(&(*NodePtr)->lines);
	 print_tree(&rightPtr);
	}
}
void addworktoTree(string Word, TREELink *trPtr, int linenum){ // adding a new word to the tree
   string newword; 
   while(!Word.empty()){
    newword = seperateword(Word);
    insertTree(trPtr, newword,1,linenum);
    Word.erase(0,newword.length());
}
}
void toLowerCase(string &str)  // change all words to lower case in order to sort in tree properly
{
	const int length = str.length();
	for(int i=0; i < length; ++i)
	{
		str[i] = tolower(str[i]);
	}
}

int main() {
 string LineString;
 string newstring;
 string newword;
 string Str;
 int linenum;
 TREELink Tptr;
while(getline(cin ,LineString)){
//   getline(cin , LineString);  
  cout <<"LineString:" << LineString << endl;
   newstring = LineString.c_str();
   cout <<"newstring:" << newstring << endl;
   cout << newstring.length() << endl;
   Str= LineString;
   toLowerCase(Str);  // change words to lower case
   cout << "1" << endl;
   linenum= linenum+1;
   cout << "2" << endl;
if(newstring!= "\n"){ 
while(Str != ""){ // while not hitting  a blank
cout << "3" << endl;
newword = seperateword(Str);
cout << "4" << endl;
insertTree(&Tptr, newword,1,linenum);
cout << "5" << endl;
Str.erase(0,newword.length()+1);
cout << "6" << endl;
}
}
else continue;
}
print_tree(&Tptr);
return 0;
}
