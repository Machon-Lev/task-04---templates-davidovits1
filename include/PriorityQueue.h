#pragma once

#include <iostream>
#include <list>
#include <exception>


struct MyComparator {
	/// <summary>
	/// An operator that compares two templates
	/// </summary>
	int operator()(int a, int b) const {
		return a - b;
	}
};
// any templates?
//template <class T>

/// <summary>
/// Class for Priority Queue
/// </summary>
class PriorityQueue {
private:
	std::list<int> _priorityQueue;
   
public:

	/// <summary>
	/// Push elment into priorityQueue
	/// </summary>
	void push(const int& t)
	{
		bool isAdd = false;

		
		if (_priorityQueue.empty()) //case empty
		{
			_priorityQueue.push_front(t);
			isAdd = true;
		}
		else
		{
			auto it = _priorityQueue.begin(); //case insert to the beginning
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
		if (!isAdd) //case insert to the end
			_priorityQueue.push_back(t);
	}

	/// <summary>
	/// poll elment into priorityQueue
	/// </summary>
	int poll()
	{
		if (_priorityQueue.empty())
		{
			std::exception e("Priority Queue is empty!");
			throw e;
		}
		int res = _priorityQueue.front();
		_priorityQueue.pop_front();
		return res;
	}

};


