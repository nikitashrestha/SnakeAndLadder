
#include<iostream>
#include"Player.h"

player::player()
{
	Nscore = 0;
	Cscore = 0;
}

void player::setPlayerScore(int n) //setting score for each player
{
	Cscore = Nscore;
	if (Cscore == 95 && n == 6)
	{
		Nscore = Cscore;
	}
	else if (Cscore == 96 && (n==6 ||n==5))
	{
		Nscore = Cscore;
	}
	else if (Cscore == 97 && (n==6||n==5||n==4))
	{
		Nscore = Cscore;
	}
	else if (Cscore == 98 && (n==6||n==5||n==4||n==3))
	{
		Nscore = Cscore;
	}
	else if (Cscore == 99 && (n==6||n==5||n==4||n==3||n==2))
	{
		Nscore = Cscore;
	}
	else 
	{
		Nscore = Nscore + n;
	}
	
}

//function to get player scores

int player::getPlayerNewScore()
{
	return Nscore;
}

int player::getPlayerCurrentScore()
{
	return Cscore;
}

//functions to set and get player position

void player::setPlayerPosition(player &obj)
{
	int n = obj.getPlayerNewScore();
	Ppos[0].setdata();
	Ppos[0].setposition(n);
}

int player::getX()
{
	return Ppos[0].getx();
}

int player::getY()
{
	return Ppos[0].gety();
}

//check for snakes and ladders

void  player::checkforSnakes(int n)
{
	switch (n)
	{
	case 16:
		Nscore = 7;
		break;

	case 54:
		Nscore = 24;
		break;

	case 62:
		Nscore = 39;
		break;

	case 64:
		Nscore = 60;
		break;

	case 87:
		Nscore = 45;
		break;

	case 93:
		Nscore = 71;
		break;

	case 95:
		Nscore = 43;
		break;

	case 98:
		Nscore = 79;
		break;

	default:
		Nscore = Nscore;
		break;
	}
	
}

void player::checkforLadders(int n)
{
	switch (n)
	{
	case 1:
		Nscore = 38;
		break;

	case 4:
		Nscore = 14;
		break;

	case 9:
		Nscore = 31;
		break;

	case 28:
		Nscore = 84;		
		break;

	case 21:
		Nscore = 42;
		break;

	case 51:
		Nscore = 67;	
		break;

	case 72:
		Nscore = 91;
		break;

	case 80:
		Nscore = 99;
		break;

	default:
		Nscore = Nscore;
		break;
	}
}

