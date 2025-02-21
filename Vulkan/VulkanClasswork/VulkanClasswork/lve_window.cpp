
#include "lve_window.hpp"

// STD
#include <stdexcept>

namespace lve
{
	LveWindow::LveWindow(int w, int h, std::string name) : width(w), height(h), windowName(name)
	{
		initWindow();
	}

	LveWindow::~LveWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	bool LveWindow::shouldClose()
	{
		return glfwWindowShouldClose(window);
	}

	VkExtent2D LveWindow::getExtent()
	{
		return { static_cast<uint32_t> (width), static_cast<uint32_t> (height) };
	}

	void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create window surface");
		}
	}

	void LveWindow::initWindow()
	{
		// Initialize GLFW Library
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);	// Do not allow OpenGL
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Do not allow resize since it will be handled later in a different way

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr); // Need to send C - Style string
	}
}