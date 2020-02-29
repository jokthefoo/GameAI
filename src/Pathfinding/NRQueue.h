#pragma once
#include "NodeRecord.h"
#include <queue>

bool compareNR(const NodeRecord lhs, const NodeRecord rhs)
{
	return lhs.estimateToGoal < lhs.estimateToGoal;
}

//Some code from stack overflow https://stackoverflow.com/questions/16749723/how-i-can-find-value-in-priority-queue
template<
	class NodeRecord,
	class Container = std::vector<NodeRecord>,
	class Compare = decltype(compareNR)
> class MyQueue : public std::priority_queue<NodeRecord, Container, Compare>
{
public:
	typedef typename
		std::priority_queue<
		NodeRecord,
		Container,
		Compare>::container_type::const_iterator const_iterator;

	NodeRecord get(const NodeRecord) const
	{
		auto first = this->c.cbegin();
		auto last = this->c.cend();
		while (first != last) {
			if (*first == val) return first;
			++first;
		}
		return last;
	}
	
	NodeRecord get(const int) const
	{
		NodeRecord first = this->c.cbegin();
		NodeRecord last = this->c.cend();
		while (first != last) {
			if (*first.node == val) return first;
			++first;
		}
		return last;
	}

	bool contains(const int) const
	{
		NodeRecord first = this->c.cbegin();
		NodeRecord last = this->c.cend();
		while (first != last) {
			if (*first.node == val) return first;
			++first;
		}
		return last;
	}

	void remove(const int) const
	{
		NodeRecord first = this->c.cbegin();
		NodeRecord last = this->c.cend();
		while (first != last) {
			if (*first.node == val)
			{
				this->c.erase(first);
				std::make_heap(this->c.begin(), this->c.end(), this->comp);
			}
			++first;
		}
	}
};
