#include "Rockets.h"


Rockets::Rockets() {

	rocketTexture = LoadTexture("resources/rocket.png");
	for (int i = 0; i < rocketSize; i++) {
		rockets.push_back(Rocket(rocketTexture));
	}
	lifespan = rockets.front().getDna().getLifespan();
}
Rockets::~Rockets() {
}

void Rockets::draw(){
	for (auto& rocket : rockets) {
		rocket.draw();
	}
	DrawText(TextFormat("Generation count : %d", generation), 0, 40, 30, WHITE);
}

void Rockets::update(){
	//update movement of each rocket
	for (auto& rocket : rockets) {
		rocket.update(count);
	}
	count++;
	//reset for new generation
	if (count == lifespan) {
		evaluate();
		selection();
		count = 0; 
		generation++;
	}
}

void Rockets::evaluate(){
	float maxFitness = 0;

	//get max fitness
	for (auto& rocket : rockets) {
		rocket.calculateFitness();
		maxFitness = std::max(maxFitness, rocket.getFitness());
	}
	//normalize fitnesses
	for_each(rockets.begin(), rockets.end(), [&maxFitness](Rocket& rocket) { 
		rocket.setFitness(rocket.getFitness() / maxFitness);
	});
	//add to matingpool based off fitness
	for (auto& rocket : rockets) {
		int n_rocket = rocket.getFitness() * 100;
		for (int i = 0; i < n_rocket; i++) {
			matingPool.push_back(rocket);
		}
	}
}

void Rockets::selection(){
	
	for (int i = 0; i < rockets.size(); i++) {
		//pick random rocket and cross over dna based on pick
		int indexA = Random::Float() * (matingPool.size() - 1);
		int indexB = Random::Float() * (matingPool.size() - 1);
		Dna parentA = matingPool[indexA].getDna();
		Dna parentB = matingPool[indexB].getDna();
		Dna child  = parentA.Crossover(parentB);
		rockets[i].resetMovement(); //reset necessary variables and movement varaibles
		rockets[i].setDna(child); //set child dna to current rocket
	}
	matingPool.clear();
}

