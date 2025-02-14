
#include "lve_window.hpp"

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

	void LveWindow::initWindow()
	{
		// Initialize GLFW Library
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);	// Do not allow OpenGL
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Do not allow resize since it will be handled later in a different way

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr); // Need to send C - Style string
	}
}