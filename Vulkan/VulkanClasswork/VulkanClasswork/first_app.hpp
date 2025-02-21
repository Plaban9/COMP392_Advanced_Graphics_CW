#pragma once
// The purpose of this class is to control the application.
// Manager of sorts.

#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_engine_swap_chain.hpp"
#include "lve_window.hpp"

// STD
#include<memory>
#include<vector>

namespace lve
{
	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp &operator=(const FirstApp &) = delete;

		void run();

	private:
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		LveWindow lveWindow{ WIDTH, HEIGHT, "VULKAN CLASSWORK" };
		LveDevice lveDevice{ lveWindow };
		//LvePipeline	lvePipeline{ lveDevice, "Shaders/simple_shader.vert.spv", "Shaders/simple_shader.frag.spv", LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT) };

		LveEngineSwapChain lveSwapChain{ lveDevice, lveWindow.getExtent() };
		std::unique_ptr<LvePipeline> lvePipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;

	};
}

