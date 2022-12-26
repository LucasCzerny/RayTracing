#include "Renderer.h"

void Renderer::SetViewportSize(int32_t width, int32_t height)
{
	if (m_Data.Image)
	{
		if (m_Data.Image->GetWidth() == width && m_Data.Image->GetHeight() == height)
			return;

		m_Data.Image->Resize(width, height);
	}
	else
	{
		m_Data.Image = std::make_shared<Walnut::Image>(width, height, Walnut::ImageFormat::RGBA);
	}

	delete[] m_Data.ImageData;
	m_Data.ImageData = new uint32_t[width * height];
}

void Renderer::RenderScene(const Scene& scene)
{
	m_Data.Scene = scene;

	uint32_t width = m_Data.Image->GetWidth();
	uint32_t height = m_Data.Image->GetHeight();

	std::cout << width << " - " << height << "\n";

	for (uint32_t y = 0; y < height; y++)
	{
		for (uint32_t x = 0; x < width; x++)
		{
			glm::vec2 uv = { (float)x / (float)width, (float)y / (float)height };
			uv = 2.0f * uv - 1.0f;

			m_Data.ImageData[x + y * width] = PerPixel(uv);
		}
	}

	m_Data.Image->SetData(m_Data.ImageData);
}

Color Renderer::PerPixel(const glm::vec2& uv)
{
	const Sphere& sphere = m_Data.Scene.Spheres[0];
	const Camera& cam = m_Data.Scene.ViewCamera;

	glm::vec3 rayDirection = cam.ViewDirection + glm::vec3(uv.x, uv.y, 0.0f);

	float a = glm::dot(rayDirection, rayDirection);
	float b = 0.0f;
	float c = -(sphere.Radius * sphere.Radius);

	for (int i = 0; i < 3; i++)
	{
		b += 2.0f * rayDirection[i] * (cam.Position[i] - sphere.Center[i]);

		float parenthesis = (cam.Position[i] + sphere.Center[i]);
		c += parenthesis * parenthesis;
	}
		
	c *= c;

	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return Color({ 0.0f, 0.0f, 0.0f });

	float denominator = 2 * a;

	float firstSolution = (-b - glm::sqrt(discriminant)) / denominator;
	// float secondSolution = (-b + glm::sqrt(discriminant)) / denominator;

	glm::vec3 intersection = cam.Position + rayDirection * firstSolution;
	glm::vec3 normal = intersection - sphere.Center;

	float intensity = (1 - firstSolution);

	static const glm::vec3 lightDirection(2.0f, -1.0f, 1.0f);
	
	float lightFactor = std::max(glm::dot(glm::normalize(lightDirection), glm::normalize(normal)), 0.0f);

	return Color(lightFactor * glm::vec3(1.0f, 0.0f, 1.0f));
}
