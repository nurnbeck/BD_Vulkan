#include "Window.h"
#include "BDMesh.h"

namespace BDEngine
{

	Window::Window()
	{
	}
	

	Window::~Window()
	{
	}

	int Window::Create()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		window = glfwCreateWindow(windowWidth, windowHeight, "Beamdog", nullptr, nullptr);

		return 0;
	}
}
