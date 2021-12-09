#pragma once

template <class T>
class TQueue
{
	T* arr;
	int MaxSize;
	int head, tail;
	int count;
public:
	TQueue(int size = 10)
	{
		if (size <= 0)
			throw - 1;
		MaxSize = size;
		arr = new T[MaxSize];
		head = 0; tail = -1;
		count = 0;
	}

	/*TQueue(const TQueue<T>& c)
	{
		MaxSize = c.MaxSize;
		head = c.head; tail = c.tail;
		count = c.count;
		delete[] arr;
		arr = new T[MaxSize];
		for (int i = 0; i < count; i++)
		{
			arr[i] = c.arr[i];
		}
	}*/

	~TQueue() { delete[] arr; }

	bool Empty()const { return count == 0; }
	bool Full()const { return count == MaxSize; }

	void Push(T c)
	{
		if (Full()) throw - 1;
		else {
			tail = (tail + 1) % MaxSize;
			arr[tail % MaxSize] = c;
			count++;
		}
	}

	T Pop()
	{
		if (Empty()) throw - 1;
		else
		{
			T res = arr[head];
			head = (head + 1) % MaxSize;
			count--;
			return res;
		}
	}


	T Back() const
	{
		return arr[tail];
	}
	T Front() const
	{
		return arr[head];
	}

	/*void print()
	{
		for (int i = 0; i < count; i++)
			cout << arr[i] << ' ';
		cout << endl << "head " << this->Front() << endl;
		cout << "tail " << this->Back() << endl;
	}*/

	int GetMaxSize() { return MaxSize; }
	int GetSize() { return count; }
	int GetHead() { return head; }
	int GetTail() { return tail; }
}; 

