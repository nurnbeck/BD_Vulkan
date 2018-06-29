#pragma once

#include <GLFW/glfw3.h>
namespace BDEngine
{
	class Window
	{
	public:
		Window();
		~Window();

		int Create();

		GLFWwindow* window;

		//dimensions for the window
		int windowWidth = 1280;
		int windowHeight = 720;
	private:

		
	};
}

