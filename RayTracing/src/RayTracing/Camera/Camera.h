#pragma once

#include "Dependencies.h"

struct Camera
{
	glm::vec3 Position;
	glm::vec3 ViewDirection;

	Camera() = default;
	Camera(const glm::vec3& position, const glm::vec3& viewDirection)
		: Position(position), ViewDirection(viewDirection) {}
};