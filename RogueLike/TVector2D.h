#pragma once

template <typename T>

class TVector2D
{
public:
	T x;
	T y;

	TVector2D()
	{
		x = T();
		y = T();
	}

	TVector2D(T Inx, T Iny)
	{
		x = Inx;
		y = Iny;
	}

	TVector2D operator+(const TVector2D<T>& InVector)
	{
		return TVector2D(x + InVector.x, y + InVector.y);
	}

	bool operator==(const TVector2D<T>& InVector)
	{
		return x == InVector.x && y == InVector.y;
	}

	void operator+=(const TVector2D<T>& InVector)
	{
		x += InVector.x;
		y += InVector.y;
	}

};
