#pragma once
#include<iostream>
#include<cstring>
#include"Position.h"
#include"Dice.h"

class player
{
private:
	 int Nscore;
	 int Cscore;
	position *Ppos = new position;

public:
	player();
	void setPlayerScore(int n);
	int getPlayerCurrentScore();
	int getPlayerNewScore();
	void setPlayerPosition(player &obj);
	int getX();
	int getY();
	void checkforSnakes(int n);
	void checkforLadders(int n);
	
};

