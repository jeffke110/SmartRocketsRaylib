#pragma once
#ifndef ROCKET_H
#define ROCKET_H


#include "raylib.h"
#include "Random.h"
#include "Dna.h"
#include <cmath>
#include <iostream>

class Rocket {


public:
	Rocket(Texture2D &rocketTexture);
	~Rocket();

	void draw();
	void update(int count);
	void calculateFitness();
	
	float getFitness();
	void setFitness(float input);

	void resetMovement();

	Dna getDna();
	void setDna(Dna dna);


private:
	float width = 22.0f;
	float height = 45.0f;

	Dna dna;
	float fitness = 0.1;

	bool dead = false;
	bool hit = true;
	int hitTimer = 0;


	Rectangle enemySpaceship;
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	Texture2D rocketTexture;
	
};


#endif // !ROCKET_H

