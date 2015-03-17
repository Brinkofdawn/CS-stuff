#include "position.h"
#include <cstdio>
#include <cstdlib> 
#include <cmath> 
#include <iostream>
enum direction{NotMove,EAST, WEST,NORTH, SOUTH}; 

//Thinh Ly whole file

void position::position1(int Size){
	srand(time(NULL));
	this->x = rand() % (Size-1) + 1;
	this->y = rand() % Size;
	this->direction = rand() % 4 +1;
}
void position::position2(int Size){
	srand(time(NULL));
	this->x = 0;
	this->y = rand() % Size;
	this->direction = 0;
}
void position::position3(int Size){
	srand(time(NULL));
    this->x = Size-1;
    this->y = rand() % Size;
	this->direction =0;
}
int position::getx(){
	return this->x;
}
int position::gety(){
	return this->y;
}
int position::getdirection(){
	return this->direction;
}
bool position::equalpos(position Pos){
	return this->x == Pos.getx() && this->y == Pos.gety();
}
float position::distance(position Pos){// returns the distance between two points
	float x;
	float y;
	float results;
	x = this->x - Pos.getx();
	y = this->y - Pos.gety();
	results = sqrt(x*x+y*y);
	return results;
}
void position::movingPos(int Size){// movement logic for the positions
	int dir;
	dir = this->direction;
	switch(dir){
	case NotMove:
		break;
	case EAST:
		if (this->x < Size-1){
			this->x = this->x +1;
		}
		else {
			this->direction = this->direction + 1;
			this->x = this->x-1;
		}
		break;
	case WEST:
		if (this->x > 1){
			this->x = this->x -1;
		}
		else {
			this->direction = this->direction -1;
			this->x = this->x +1;
		}
		break;
	case NORTH:
		if (this->y > 1){
			this->y = this->y -1;
		}
		else {
			this->direction = this->direction +1;
			this->y = this->y +1;
		}
		break;
	case SOUTH:
		if (this->y < Size-1){
			this->y = this->y +1;
		}
		else {
			this->direction = this->direction -1;
			this->y = this->y -1;
		}
		break;
		}
}