#include "Color.h"

Color::Color(const glm::vec3& color)
{
	m_ColorValue = 0xff000000;

	for (int i = 0; i < 3; i++)
	{
		uint8_t channel = color[i] * 255u;
		m_ColorValue |= (channel << (8 * i));
	}
}

Color::Color(const glm::vec4& color)
{
	for (int i = 0; i < 4; i++)
	{
		uint8_t channel = color[i] * 255u;
		m_ColorValue |= (channel << (8 * i));
	}
}

Color::operator uint32_t()
{
	return m_ColorValue;
}