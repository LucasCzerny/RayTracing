#pragma once

#include "Dependencies.h"

#include "RayTracing/Sphere/Sphere.h"
#include "RayTracing/Camera/Camera.h"

class Scene
{
public:
	std::vector<Sphere> Spheres;
	Camera ViewCamera;

	Scene() = default;
	Scene(const std::vector<Sphere>& spheres, const Camera& camera)
		: Spheres(spheres), ViewCamera(camera) {}
};

