
#ifndef BOARD_H
#define BOARD_H
#include "Mules.h"
#include "Source.h"
#include "Receiver.h"


class Board
{
public:
	Board(Receiver *R, Source *S, Mules *M);
	void makeBoard(int Size);
private:
	Receiver *R;
	Source *S;
	Mules *M;
	/* data */
};
#endif