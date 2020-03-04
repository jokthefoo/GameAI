#pragma once
#include "NodeRecord.h"
#include <set>

class MySet : public std::multiset<NodeRecord>
{

public:
	NodeRecord get(const int val) const
	{
		auto first = this->cbegin();
		auto last = this->cend();
		while (first != last) {
			if ((*first).node == val) return *first;
			++first;
		}
		return *last;
	}

	bool contains(const int val) const
	{
		auto first = this->cbegin();
		auto last = this->cend();
		while (first != last) {
			if ((*first).node == val) return true;
			++first;
		}
		return false;
	}

	void remove(const int val)
	{
		auto first = this->cbegin();
		auto last = this->cend();
		while (first != last) {
			if ((*first).node == val)
			{
				this->erase(first);
				return;
			}
			++first;
		}
	}
};