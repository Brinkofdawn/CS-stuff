// Authors: Arun Donti , Thinh Ly


#include <fstream>
#include <cstdlib> 
#include <cstdio> 
#include <iostream>
#include <cstring>
#define DEBUG 1
using namespace std;



class Line
{
public:
    void insert(Line *oldline , Line newline);
    void print_line(Line *sPtr);
    friend class Word;
    int linenumber;  // line number
    Line *linepointer; // pointer to next line number
    void setLine(int linenumber, Line *linepointer);


};


void Line::setLine(int linenumber, Line *linepointer)
{
    this->linenumber=linenumber;
    this->linepointer=linepointer;
}




void Line::insert(Line *oldline , Line newline)
{
    Line *currentline;
    Line *nextline;

    nextline= &newline;
    currentline=oldline;

    if(currentline==NULL) // insert newline if current pointer is NULL
    {
        oldline= nextline;
if (DEBUG==1){
  printf("a");
}
    }

    else 
        { 
            while(currentline!=NULL)  // recurse to find the end of list
            {
                currentline=currentline->linepointer;
                
                    if(currentline->linepointer==NULL)
                    {
                        currentline->linepointer=nextline;
                        break;

                    }
            } 
if (DEBUG==1){
  printf("b");
}

        }

}

void Line::print_line(Line *sPtr)
    {
        // check if the tree is empty before traversing
        if (sPtr!=NULL)
        {
            print_line(sPtr->linepointer);
            cout<< " "<< sPtr->linenumber;
if (DEBUG==1){
  printf("c");
}
        }

    }


class Word
{
public:
    string name; // the word itself
    int amount; // the number of occurances
    Line lines; // the lines it appears in
    void setWord(string word, int amount, Line lines);
    void modify (Word *name, Line newline);
    friend class Tree;


};

void Word::setWord(string name , int amount, Line lines)
    {
        this->name=name;
        this->amount=amount;
        this->lines= lines;

    }





void Word::modify (Word *name, Line newline)
{
    name->amount= name->amount++;
    newline.insert(&name->lines, newline);

}


class Tree
{
public:
 
    Word word;
    Tree *leftpointer;
    Tree *rightpointer;
    void setTree(Word word, Tree *leftpointer, Tree *rightpointer);
    void addtree(Word word, Tree *treepointer);
    void print_tree(Tree *sPtr);
};



void Tree::setTree(Word word, Tree *leftpointer, Tree *rightpointer)
{
    this->word=word;
    this->leftpointer=leftpointer;
    this->rightpointer=rightpointer;
}


void Tree::addtree(Word word, Tree *treepointer)
{
    Tree *previousPtr;
    Tree *currentPtr;
    Tree *newPtr;
    newPtr->word=word;
    newPtr->leftpointer=leftpointer;
    newPtr->rightpointer=rightpointer;
    
    currentPtr=treepointer;

    if (currentPtr==NULL) // set the null pointer to the treepointer
    {
        treepointer= newPtr;
      
        
    }

    else
    
    {
        if (((newPtr->word).name).compare((currentPtr->word).name) < 0)// if new word is less than
        {
if (DEBUG==1){
  printf("e");
}
            if (currentPtr->leftpointer==NULL)
            {
                currentPtr->leftpointer=newPtr;
if (DEBUG==1){

  printf("f");
}
            }

            else 
            {
                addtree(word, currentPtr->leftpointer);
if (DEBUG==1){
  printf("g");
}
            }
        }


        else if (((newPtr->word).name).compare((currentPtr->word).name) > 0)// if new word is greater than

        {
if (DEBUG==1){
  printf("h");
}
            if (currentPtr->rightpointer==NULL)
            {
                currentPtr->rightpointer=newPtr;
            }

            else 
            {
                addtree(word, currentPtr->rightpointer);

            }
        }

        else

        {
            Line newline;       // if already in the tree increment the amount and add the linenumber
            newline= word.lines;
            currentPtr->word.amount++;
            newline.insert(currentPtr->word.lines.linepointer, newline);
        }



    }
}


void Tree::print_tree(Tree *sPtr)
    {
        // check if the tree is empty before traversing
        if (sPtr!=NULL)
        {
if (DEBUG==1){
  printf("i");
}
            print_tree(sPtr->leftpointer);
            cout<< sPtr->word.name <<"appears"<<sPtr->word.amount<<"times on line(s)";
            while(sPtr->word.lines.linepointer!=NULL)
            {
            (sPtr->word.lines).print_line(sPtr->word.lines.linepointer);
            }
            print_tree(sPtr->rightpointer);
        }

    }


int main()
{

Tree *head=NULL;// pointer to top of BST


ifstream file("test.txt"); // file that we are taking in
    int LineCount = 0;
    char* str = new char[999999999];

    while(file) // if the file actually exists
    {
        LineCount++;
        file.getline(str, 999999999);
        char * validchars = strtok(str," ,.?!"); // take out all the punctuation
        while(validchars !=NULL) 
        {
        	string goodstring= string(validchars);// turn character array into string
        	Line newline; // create a new Line object
        	newline.linenumber= LineCount;
        	newline.linepointer=NULL;
			
        	// create the word object 
			Word newword;
            newword.name=goodstring;
            newword.amount=0;
            newword.lines=newline;


		
			//head->addtree(newword, head);// add to BST  NOT WORKING, need to fix

            if(DEBUG==1){
          cout<<newword.name<<newword.amount<<newword.lines.linenumber;
          cout<< goodstring<< endl;}
            validchars = strtok(NULL," ,.?!");
        }
    }
    file.close();

   //head->print_tree(head); NOT WORKING
    

    return 0;
}




