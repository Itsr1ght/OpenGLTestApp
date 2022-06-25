#pragma once
#include <string>

struct WindowProps
{
	int width;
	int height;
	std::string name;
};

class Window
{
public:
	~Window();
	static Window Create(WindowProps props);
	bool isRunning();
	void ClearScreen();
	int getWidth();
	int getHeight();
	std::string getName();

private:
	WindowProps props = { 720 , 460, "Hello OpenGL" };
	Window(WindowProps props);

};

