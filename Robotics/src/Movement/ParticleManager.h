#ifndef PARTICLEMANAGER_H_
#define PARTICLEMANAGER_H_

#include <vector>
#include <algorithm>
#include <queue>

#include "../Utils/Position.h"
#include "../Movement/Particle.h"
#include "../Utils/GridMap.h"
#include "../Managers/ConfigurationManager.h"
#include "../Utils/Location.h"

using namespace std;

class ParticleManager {
private:
	static const int PARTICLE_NUM = 50;
	static const float BELIEF_THRESHOLD = 0.4;
	priority_queue<Particle*> particles;
	void deleteUnreliableParticles(double minBelife);
	bool isGoodNeighbour(Location* neighbourLoc);
	GridMap* grid;
	void FilterParticles();
public:
	ParticleManager(GridMap* gridMap, double yawRobot);
	void updateAll(Position* delta, double* laserScan, Location* nextLocation);
	void FillParticlesWithNewMutations();
	Position* GetProbablyPosition();
	virtual ~ParticleManager();
};

#endif
