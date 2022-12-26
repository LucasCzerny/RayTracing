#pragma once

#include "Dependencies.h"

class Color
{
private:
	uint32_t m_ColorValue;

public:
	Color(const glm::vec3& color);
	Color(const glm::vec4& color);

	operator uint32_t();
};

