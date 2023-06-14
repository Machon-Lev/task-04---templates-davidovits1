#pragma once

#include <iostream>
#include <list>
#include <exception>

struct MyComparator {
	int operator()(int a, int b) const {
		return a - b;
	}
};
// any templates?
//template <class T>
class PriorityQueue {
private:
	std::list<int> _priorityQueue;// = new std::list<int>();
   
public:
	//PriorityQueue()
	//{
	//	//_priorityQueue = new std::list<int>();
	//}

	~PriorityQueue()
	{
		_priorityQueue.clear();
		//delete _priorityQueue;
		//_priorityQueue = NULL;
	}

   // You need to complete the implement : 
	void push(const int& t)
	{
		bool isAdd = false;

		if (_priorityQueue.empty())
		{
			_priorityQueue.push_front(t);
			isAdd = true;
		}
		else
		{
			auto it = _priorityQueue.begin();
			if (MyComparator()(*it, t) > 0)
			{
				_priorityQueue.push_front(t);
				isAdd = true;
			}
				
			else
			{
				for (++it; it != _priorityQueue.end() ; ++it)
				{
					if (MyComparator()(*it, t) > 0)
					{
						_priorityQueue.insert(--it, t);
						isAdd = true;
						break;

					}
				}
			}

		}
		if (!isAdd)
			_priorityQueue.push_back(t);
	}
	int poll()
	{
		if (_priorityQueue.empty())
		{
			std::exception e("empty Priority Queue");
			//e.what;
			throw e;
		}
		int i = _priorityQueue.front();
		_priorityQueue.pop_front();
		return i;
	}

};


