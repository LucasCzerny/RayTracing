#include "RayTracingLayer.h"

#include "RayTracing/Camera/Camera.h"
#include "RayTracing/Sphere/Sphere.h"
#include "RayTracing/Scene/Scene.h"

void RayTracingLayer::OnUIRender()
{
	static Camera cam({ 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, -1.0f });
	static Sphere sphere({ 0.0f, 0.0f, 0.0f }, 0.5f);

	static Scene scene({ sphere }, cam);

	ImGui::Begin("Settings");

	if (ImGui::Button("Render"))
	{
		m_Renderer.RenderScene(scene);
	}

	ImGui::End();

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

	ImGui::Begin("Viewport");

	int32_t viewportWidth = ImGui::GetContentRegionAvail().x;
	int32_t viewportHeight = ImGui::GetContentRegionAvail().y;
	
	m_Renderer.SetViewportSize(viewportWidth, viewportHeight);

	std::shared_ptr<Walnut::Image> image = m_Renderer.GetFinalImage();

	if (image)
	{
		ImVec2 imageSize = { (float)image->GetWidth(), (float)image->GetHeight() };
		ImGui::Image(image->GetDescriptorSet(), imageSize);
	}

	ImGui::End();

	ImGui::PopStyleVar();
};