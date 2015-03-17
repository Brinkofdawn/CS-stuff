// Authors: Arun Donti , Thinh Ly


#include <fstream>
#include <cstdlib> 
#include <cstdio> 
#include <iostream>
#include <cstring>
#define DEBUG 0
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
    Word *leftpointer;// left subtree
    Word *rightpointer; // right subtree
    void setWord(string name , int amount, Line lines, Word *leftpointer, Word *rightpointer);
    void modify (Word *name, Line newline);
    void addtree(Word word, Word **treepointer);
    void print_tree(Word *sPtr);

    friend class Tree;


};

void Word::setWord(string name , int amount, Line lines, Word *leftpointer, Word *rightpointer)
    {
        this->name=name;
        this->amount=amount;
        this->lines= lines;
        this->leftpointer=leftpointer;
        this->rightpointer=rightpointer;

    }





void Word::modify (Word *name, Line newline)
{
    name->amount= name->amount++;
    newline.insert(&name->lines, newline);

}



void Word::addtree(Word word, Word **treepointer)
{


    if (*treepointer==NULL) // set the null pointer to the treepointer
    {
         (**treepointer).name=word.name;
         (**treepointer).amount=word.amount;
         (**treepointer).lines=word.lines;

        
    }

    else
    
    {
        if ((word.name).compare((**treepointer).name) < 0)// if new word is less than
        {
            addtree(word,&((**treepointer)).leftpointer);
        }


        else if ((word.name).compare((**treepointer).name) > 0)// if new word is greater than

        {
           addtree(word,&((**treepointer)).rightpointer);
        }

        else

        {
            Line newline;       // if already in the tree increment the amount and add the linenumber
            word.lines;
            word.amount++;
           // Line *head= &(word.lines)
            newline.insert((&word.lines), newline);
        }



    }
}


void Word::print_tree(Word *sPtr)
    {
        // check if the tree is empty before traversing
        if (sPtr!=NULL)
        {
if (DEBUG==1){
  printf("i");
}
            print_tree(sPtr->leftpointer);
            cout<< sPtr->name <<"appears"<<sPtr->amount<<"times on line(s)";
           // while(sPtr->lines!=NULL)
           // {
           // (sPtr->word.lines).print_line(sPtr->word.lines.linepointer);
           // }
            print_tree(sPtr->rightpointer);
        }

    }


int main()
{

Word *head=NULL;// pointer to top of BST


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


		
			head->addtree(newword, &head);// add to BST  NOT WORKING, need to fix

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




