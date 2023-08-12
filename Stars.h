#pragma once
#ifndef STARS_H
#define STARS_H

#include "raylib.h"
#include "Random.h"
#include <vector>

class Stars
{
public:
	Stars();
	void draw();
private:
	std::vector<Vector2> stars;

};
#endif // STARS_H



