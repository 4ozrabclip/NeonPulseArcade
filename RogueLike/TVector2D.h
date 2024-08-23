#pragma once

template <typename T>

class TVector2D
{
public:
	T X;
	T Y;

	TVector2D(T InX, T InY)
	{
		X = InX;
		Y = InY;
	}

	TVector2D operator+(const TVector2D<T>& InVector)
	{
		return TVector2D(X + InVector.X, Y + InVector.Y);
	}

	bool operator==(const TVector2D<T>& InVector)
	{
		return X == InVector.X && Y == InVector.Y;
	}

	void operator+=(const TVector2D<T>& InVector)
	{
		X += InVector.X;
		Y += InVector.Y;
	}

};
