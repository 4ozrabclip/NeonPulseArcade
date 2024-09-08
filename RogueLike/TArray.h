#pragma once

template <typename T>
class TArray
{
public:
	TArray(int InitialCapacity = 5) 
	{
		Capacity = InitialCapacity;
		Size = 0;
		Data = new T[Capacity];
	}
	~TArray() 
	{
		delete[] Data;
	}

	void AddElement(T& NewElement)
	{
		if (Size >= Capacity)
		{
			Resize(Capacity * 2);
		}
		Data[Size] = NewElement;
		++Size;
	}
	T& GetElement(int Index)
	{
		return Data[Index];
	}
	bool IsValidIndex(int Index)
	{
		return (Index >= 0 && Index <= Size);
	}
	int Num()
	{
		return Size;
	}
	void RemoveElement(int Index)  //Need to move everything across
	{
		//if (!IsValidIndex(Index))
		//{
		//	throw std::out_of_range("Index out of range");
		//}

		for (int i = Index; i < Size - 1; ++i)
		{
			Data[i] = Data[i + 1];
		}
		//delete Data[Index];
		--Size;
	}
	bool Contains(T& Element)
	{
		for (size_t DataIndex = 0; DataIndex < Size; DataIndex++)
		{
			if (Data[DataIndex] == Element)
			{
				return true;
			}
		}
		return false;
	}

private:
	T* Data;
	int Capacity;
	int Size;

	void Resize(int NewCapacity) 
	{
		T* NewData = new T[NewCapacity];

		for (int DataIndex = 0; DataIndex < Size; ++DataIndex)
		{
			NewData[DataIndex] = Data[DataIndex];
		}

		delete[] Data;

		Data = NewData;
		Capacity = NewCapacity;

		if (Size > NewCapacity)
		{
			Size = NewCapacity;
		}
	}
};
