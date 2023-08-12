#pragma once
#ifndef ROCKETS_H
#define ROCKETS_H

#include "Rocket.h"

class Rockets {


public:

	Rockets();
	~Rockets();
	void draw();
	void update();
	void evaluate();
	void selection();


private:
	int count = 0;
	int generation = 0;
	std::vector<Rocket> rockets;
	std::vector<Rocket> matingPool;
	int rocketSize = 100;
	Texture2D rocketTexture;
	int lifespan;

};




#endif // ROCKETS_H



