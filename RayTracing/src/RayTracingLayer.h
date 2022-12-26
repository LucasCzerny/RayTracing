#pragma once

#include <Walnut/Application.h>
#include <Walnut/Image.h>

#include "RayTracing/Renderer/Renderer.h"

class RayTracingLayer : public Walnut::Layer
{
private:
	Renderer m_Renderer;

public:
	virtual void OnUIRender() override;
};

