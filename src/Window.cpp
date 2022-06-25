#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <exception>


Window *instance = nullptr;
GLFWwindow* window;

Window::Window(WindowProps props)
{
	this->props = props;

	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		std::exit(-1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(this->props.width , this->props.height , this->props.name.c_str() , NULL , NULL);

	if (!window)
	{
		glfwTerminate();
		std::cout << "Failed to initialize glfw Window" << std::endl;
		std::exit(-1);
	}
	
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		std::exit(-1);
	}

}

Window::~Window()
{
	if (window) {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	if (instance)
		free(instance);
}

Window Window::Create(WindowProps props)
{
	if (!instance)
		instance = new Window(props);
	return *instance;
}

bool Window::isRunning()
{
	return glfwWindowShouldClose(window);
}

void Window::ClearScreen()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

int Window::getWidth()
{
	return this->props.width;
}

int Window::getHeight()
{
	return this->props.height;
}

std::string Window::getName()
{
	return this->props.name;
}