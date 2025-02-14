#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace lve
{
	class LveWindow		   //Little Vulkan Engine Window
	{
	public:
		LveWindow(int w, int h, std::string name);
		~LveWindow();

	private:
		void initWindow();

		const int width;
		const int height;

		std::string windowName;

		GLFWwindow* window;
	};
}
