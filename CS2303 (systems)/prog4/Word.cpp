#include <iostream>
#include <string>
#include "Tree.h"
#include "Line.h"
#include "Word.h"
using namespace std;


void Word::set_values (string word, int amount, Line lines)
{ // set the initial values
	word=word;
	amount=amount;
	lines=lines;
}



void Word::modify (Word *name, Line newline)
{
	name->amount= name->amount++;
	Line.insert(&name->lines, newline);

}