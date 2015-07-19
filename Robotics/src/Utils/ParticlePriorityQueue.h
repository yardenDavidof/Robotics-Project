/*
 * ParticlePriorityQueue.h
 *
 *  Created on: Jul 19, 2015
 *      Author: colman
 */

#ifndef PARTICLEPRIORITYQUEUE_H_
#define PARTICLEPRIORITYQUEUE_H_

#include <queue>
#include <vector>
#include "../Movement/Particle.h"
#include <functional>

using namespace std;

class ParticlePriorityQueue {
private:

	priority_queue<Particle*,vector<Particle*>, std::greater<Particle*> > elements;

public:
	bool isEmpty();
	void put(Particle* particle);
	priority_queue<Particle*,vector<Particle*>, std::greater<Particle*> > getElements();
	int getElementsSize();
	Particle* get();
	void print();
	ParticlePriorityQueue();
	virtual ~ParticlePriorityQueue();
};

#endif /* PARTICLEPRIORITYQUEUE_H_ */
