#pragma once

#include <Walnut/Image.h>

#include "Dependencies.h"

#include "RayTracing/Color/Color.h"

#include "RayTracing/Camera/Camera.h"
#include "RayTracing/Sphere/Sphere.h"
#include "RayTracing/Scene/Scene.h"

class Renderer
{
private:
	struct RenderData
	{
		Scene Scene;

		std::shared_ptr<Walnut::Image> Image;
		uint32_t* ImageData;
	} m_Data;

public:
	void SetViewportSize(int32_t width, int32_t height);

	void RenderScene(const Scene& scene);
	std::shared_ptr<Walnut::Image> GetFinalImage() { return m_Data.Image; }

private:
	Color PerPixel(const glm::vec2& uv);
};