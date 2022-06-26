#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>


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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwPollEvents();
	glViewport(0, 0, props.width, props.height);
}

void Window::Destroy()
{
	if (window) {
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	delete instance;
}

void Window::setVSync(bool vsync=true)
{
	glfwSwapInterval(vsync);
}

int Window::getWidth()
{
	return this->props.width;
}

int Window::getHeight()
{
	return this->props.height;
}

std::string Window::getTitle()
{
	return this->props.name;
}