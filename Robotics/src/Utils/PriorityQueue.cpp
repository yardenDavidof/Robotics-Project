#include "PriorityQueue.h"

/**
 * Empty constructor for PriorityQueue
 */
PriorityQueue::PriorityQueue() {}

/**
 * The function check if the elements are empty
 */
bool PriorityQueue::isEmpty(){
	return elements.empty();
}

/**
 * The function put location in queue according to getting priority
 */
void PriorityQueue::put(Location* pos, int priority){
	Node newNode = Node();
	newNode.pos = pos;
	newNode.priority = priority;
	elements.push(newNode);
}

/**
 * Get the top in priority and pop
 */
PriorityQueue::Node PriorityQueue::get(){
	Node node = elements.top();
	elements.pop();
	return node;
}


PriorityQueue::~PriorityQueue() {}
