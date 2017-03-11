#include<iostream>
#include"Position.h"

position::position()
{
	
	x = 0; y = 0;

}

position::position(int a, int b)
{
	x = a;
	y = b;
}

void position::setdata()
{
	for (int i = 0; i < 10; i++)
	{
		if ((i + 2) % 2 == 0)
		{
			for (int j = 0; j < 10; j++)
			{
				arr[i][j] = j + 1 + (i * 10);
			}
		}

		else
		{
			for (int j = 0; j < 10; j++)
			{
				arr[i][j] = j + 1 + (i * 10);
			}
		}
	}
}

void position::setposition(int n)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == n)
			{
				if ((i + 2) % 2 == 0)
				{
					this->x = (j + 1) * 60 + 10;
					this->y=630 - i * 60;
				}

				else
				{
					this->x = 610 - j * 60;
					this->y = 630 - i * 60;
				}
			}
		}
	}
}

int position::getx()
{
	return x;
}


int position::gety()
{
	return y;
}

