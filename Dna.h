#pragma once
#ifndef DNA
#define DNA

#include "raylib.h"
#include "Random.h"
#include <vector>

class Dna
{
public:
	Dna();
	Dna(std::vector<Vector2> genesInput);
	~Dna();
	Dna Crossover(Dna input);
	
	std::vector<Vector2> getGenes();
	int getLifespan();

private:
	std::vector<Vector2> genes;
	int lifespan = 300;

};

#endif // !DNA

