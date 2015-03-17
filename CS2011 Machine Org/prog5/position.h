#ifndef POSITION_H
#define POSITION_H
class position{
public:
	int getx();
	int gety();
	int getdirection();
	void position1(int Size);
	void position2(int Size);
	void position3(int Size);
	bool equalpos(position Pos);
	float distance(position Pos);
	void movingPos(int Size);
private:
	int x;
	int y;
	int direction;
};
#endif