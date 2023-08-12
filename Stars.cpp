#include "Stars.h"


Stars::Stars()
{
	for (int i = 0; i < 400; i++) {
		Vector2 position = { Random::Float() * GetScreenWidth(), Random::Float() * GetScreenHeight() };
		stars.push_back(position);
	}
}

void Stars::draw()
{
	for (auto& star : stars) {
		DrawCircleV(star, 1, WHITE);
	}
}
