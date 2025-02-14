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

		// Becasue of RAII (Resource creation happens when initialization and clean ups are performed here)
		// Also, prevents two(multiple) pointers pointing to the same thing. Therefore, no dangling pointer at cleanup.
		LveWindow(const LveWindow&) = delete; // Delete Copy Constructor
		LveWindow& operator=(const LveWindow&) = delete; // Delete Copy Operator

		bool shouldClose();

		void createWindowSurface(VkInstance instance, VkSurfaceKHR * surface);

	private:
		void initWindow();

		const int width;
		const int height;

		std::string windowName;

		GLFWwindow* window;
	};
}
