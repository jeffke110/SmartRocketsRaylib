#include "Dna.h"

Dna::Dna()
{
	for (int i = 0; i < lifespan; i++) {
		genes.push_back({ (Random::Float() * 2 - 1) / 10, (Random::Float() * 2 - 1) / 10 });
	}
}

Dna::Dna(std::vector<Vector2> genesInput)
{
	this->genes = genesInput;
}


Dna::~Dna()
{
}

Dna Dna::Crossover(Dna input){
	std::vector<Vector2> newGenes;
	//mix genetics based off random float between 0 and 1
	for (int i = 0; i < genes.size(); i++) {
		float random = Random::Float();
		if (random > .5) {
			newGenes.push_back(genes[i]);
		}
		else {
			newGenes.push_back(input.getGenes()[i]);
		}
	}
	return Dna(newGenes);
}

std::vector<Vector2> Dna::getGenes()
{
	return genes;
}

int Dna::getLifespan()
{
	return lifespan;
}


