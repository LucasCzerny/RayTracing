#pragma once

#include "Dependencies.h"

struct Sphere
{
	glm::vec3 Center;
	float Radius;

	Sphere() = default;
	Sphere(const glm::vec3& center, float radius)
		: Center(center), Radius(radius) {}
};