
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
			throw std::runtime_error("Failed to create window surface");
		}
	}

	void LveWindow::frameBufferResizeCallback(GLFWwindow* window, int width, int height)
	{
		auto lveWindow = reinterpret_cast<LveWindow*>(glfwGetWindowUserPointer(window));

		lveWindow->framerBufferResized = true;
		lveWindow->width = width;
		lveWindow->height = height;
	}

	void LveWindow::initWindow()
	{
		// Initialize GLFW Library
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);	// Do not allow OpenGL
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); // Do not allow resize since it will be handled later in a different way

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr); // Need to send C - Style string
		glfwSetWindowUserPointer(window, this);
		glfwSetFramebufferSizeCallback(window, frameBufferResizeCallback);
	}
}