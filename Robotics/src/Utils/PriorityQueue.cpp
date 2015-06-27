/*
 * PriorityQueue.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {

}

bool PriorityQueue::isEmpty(){
	return elements.empty();
}
void PriorityQueue::put(Location* pos, int priority){
	Node newNode = Node();
	newNode.pos = pos;
	newNode.priority = priority;
	elements.push(newNode);
}

PriorityQueue::Node PriorityQueue::get(){
	Node node = elements.top();
	elements.pop();
	return node;
}


PriorityQueue::~PriorityQueue() {
}
