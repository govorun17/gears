#ifndef BAT_H
#define BAT_H

#include "Figure.h"
#include <math.h>

class Batmen : public Figure
{
public:
	Batmen(int size = 12, int offsetX = 100, int offsetY = 100) : Figure(size, offsetX, offsetY)
	{
	}
	void Draw(HDC dc)
	{
		Ellipse(dc, offsetX - 3*size, offsetY - 2*size, offsetX + 3*size, offsetY + 2*size);
		MoveToEx(dc, offsetX, offsetY + 2 * size, NULL);
		//1
		LineTo(dc, 0.5 * size + offsetX, size + offsetY);
		//2
		LineTo(dc, 1.5 * size + offsetX, 0.5 * size + offsetY);
		//3
		LineTo(dc, 3 * size * cos(-0.5) + offsetX, offsetY + 2 * size * sin(-0.5));
		//4
		LineTo(dc, 1.75 * size + offsetX, offsetY + 2 * size * sin(-0.5));
		//5
		LineTo(dc, 0.75 * size + offsetX, 0.01 * size + offsetY);
		//6
		LineTo(dc, 0.5 * size + offsetX, -0.8 * size + offsetY);
		//7
		LineTo(dc, 0.2 * size + offsetX, -0.3 * size + offsetY);
		LineTo(dc, -0.2 * size + offsetX, -0.3 * size + offsetY);
		LineTo(dc, -0.2 * size + offsetX, -0.3 * size + offsetY);
		LineTo(dc, -0.5 * size + offsetX, -0.8 * size + offsetY);
		LineTo(dc, -0.75 * size + offsetX, 0.01 * size + offsetY);
		LineTo(dc, -1.75 * size + offsetX, offsetY + 2 * size * sin(-0.5));
		LineTo(dc, -3 * size * cos(-0.5) + offsetX, offsetY + 2 * size * sin(-0.5));
		LineTo(dc, -1.5 * size + offsetX, 0.5 * size + offsetY);
		LineTo(dc, -0.5 * size + offsetX, size + offsetY);
		LineTo(dc, offsetX, offsetY + 2 * size);


		
	}
	bool InnerPoint(int X, int Y)
	{
		return (X - offsetX)* (X - offsetX) / (9 * size* size) + (Y - offsetY) * (Y - offsetY) / (4 * size* size) <= 0.5;
	}
};
#endif BAT_H