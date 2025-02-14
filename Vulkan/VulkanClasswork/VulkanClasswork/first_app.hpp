#pragma once
// The purpose of this class is to control the application.
// Manager of sorts.

#include "lve_window.hpp"
#include "lve_pipeline.hpp"

namespace lve
{
	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		LveWindow lveWindow{ WIDTH, HEIGHT, "VULKAN CLASSWORK" };
		LvePipeline	lvePipeline{ "Shaders/simple_shader.vert.spv", "Shaders/simple_shader.frag.spv" };
	};
}

