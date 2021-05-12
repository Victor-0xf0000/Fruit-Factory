#ifndef VECTOR2_H
#define VECTOR2_H

struct Vector2
{
	float x;
	float y;
	
	Vector2()
	{
		x = 0;
		y = 0;
	}
};

struct Vector2i
{
	int x;
	int y;

	Vector2i()
	{
		x = 0;
		y = 0;
	}

	Vector2i(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

#endif // VECTOR2_H
