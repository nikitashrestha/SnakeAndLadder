#pragma once
#include"board.h"

#include<iostream>

class position
{
private:
	int arr[10][10];
	int x, y;
	int px, py;
	
	

public:
	position();
	position(int a, int b);
	void setdata();
	void setposition(int n);
	int getx();
	int gety();
	friend class myboard;

};