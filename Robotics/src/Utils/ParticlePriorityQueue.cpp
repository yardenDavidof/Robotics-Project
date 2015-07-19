/*
 * ParticlePriorityQueue.cpp
 *
 *  Created on: Jul 19, 2015
 *      Author: colman
 */

#include "ParticlePriorityQueue.h"

ParticlePriorityQueue::ParticlePriorityQueue() {

}

bool ParticlePriorityQueue::isEmpty(){
	return elements.empty();
}
void ParticlePriorityQueue::put(Particle* particel ){

	elements.push(particel);
}

Particle* ParticlePriorityQueue::get(){
	Particle* particle = elements.top();
	elements.pop();
	return particle;
}

priority_queue<Particle*,vector<Particle*>, std::greater<Particle*> > ParticlePriorityQueue::getElements(){
return elements;
}

int ParticlePriorityQueue::getElementsSize(){
	return elements.size();
}

ParticlePriorityQueue::~ParticlePriorityQueue() {
}

