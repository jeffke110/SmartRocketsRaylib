#include "Rocket.h"


//use the distance formula to calculate fitness
float calculateDistance(Vector2 one, Vector2 two) {
	return std::sqrt((two.x - one.x) * (two.x - one.x) + (two.y - one.y) * (two.y - one.y));
}

Rocket::Rocket(Texture2D& rocketTexture) {
	enemySpaceship = { (float)GetScreenWidth() / 2 - 123 / 2, 50, 123, 80 };
	position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() - 200};
	velocity = { 0.0f, 0.0f};
	acceleration = { 0.0f, 0.0f };
	this->rocketTexture = rocketTexture;
	dna = Dna();
}
Rocket::~Rocket() {}

void Rocket::update(int count) {
	//collsiion variables with spaceship and planet
	enemySpaceship = { (float)GetScreenWidth() / 2 - 123 / 2, 50, 123, 80 };
	Rectangle rocketRec = { position.x, position.y, width, height };
	Vector2 planetVec = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	float planetRadius = 50.0f;

	//check collision with spaceship
	if (CheckCollisionRecs(rocketRec, enemySpaceship)) {
		hit = true;
		hitTimer = count;
	}
	//check collision with planet
	else if (CheckCollisionPointCircle({position.x + width / 2, position.y}, planetVec, planetRadius)) {
		dead = true;
	}
	//check edges of screen
	else if (position.x < 0 || position.x  > GetScreenWidth() ||
		position.y < 0 || position.y > GetScreenHeight()) {
		dead = true;
	}
	//move based off the genes
	else {
		acceleration = dna.getGenes()[count];
		velocity.x += acceleration.x;
		velocity.y += acceleration.y;
		position.x += velocity.x;
		position.y += velocity.y;
	}
}

void Rocket::draw() {
	float rotation = atan2f(velocity.y, velocity.x) * (180 / PI) + 90.0f;
	DrawTextureEx(rocketTexture, position, rotation, 1.0f, WHITE);
}

void Rocket::calculateFitness(){
	Vector2 targetVector = { enemySpaceship.x + (123/2), enemySpaceship.y + 40 };
	float d = calculateDistance(position, targetVector);

	//check if dead
	if (dead == true) {
		fitness = .01;
	}
	//check if hit
	else if (hit == true && hitTimer != 0) {
		fitness = 25 + (150 * (1 / hitTimer));
	}
	//avoid divide by zero
	else if(d != 0){
		fitness = ((1/d) * 1000);
	}
}


void Rocket::resetMovement()
{
	position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() - 200 };
	velocity = { 0.0f, 0.0f };
	acceleration = { 0.0f, 0.0f };
	dead = false;
	hit = false;
	fitness = 0.1;
	hitTimer = 0;
}

float Rocket::getFitness() {
	return fitness;
}
void Rocket::setFitness(float input) {
	fitness = input;
}
Dna Rocket::getDna()
{
	return dna;
}
void Rocket::setDna(Dna dna)
{
	this->dna = dna;
}