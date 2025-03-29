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
		VkExtent2D getExtent();
		bool wasWindowResized()
		{
			return framerBufferResized;
		}

		void resetWindowResizedFlag()
		{
			framerBufferResized = false;
		}

		GLFWwindow* getGLFWwindow() const
		{
			return window;
		}

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	private:
		static void frameBufferResizeCallback(GLFWwindow* window, int width, int height);
		void initWindow();

		int width;
		int height;
		bool framerBufferResized = false;

		std::string windowName;

		GLFWwindow* window;
	};
}
