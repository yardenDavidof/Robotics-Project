/*
 * PriorityQueue.h
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <queue>
#include <vector>
#include <functional>
#include "Location.h" //TODO use template

using namespace std;

class PriorityQueue {
public:
	struct Node{
		Location* pos;
		int priority;

		bool operator>(const Node& secondNode) const
	    {
			if (priority > secondNode.priority)
				return true;
			return false;
		}

	};

private:

	priority_queue<Node,vector<Node>, std::greater<Node> > elements;


public:
	PriorityQueue();

	bool isEmpty();
	void put(Location* pos, int priority);
	Node get();
	void print();
	virtual ~PriorityQueue();
};

#endif /* PRIORITYQUEUE_H_ */
