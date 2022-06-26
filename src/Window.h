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
	static Window Create(WindowProps props);
	bool isRunning();
	void ClearScreen();
	void Destroy();
	void setVSync(bool vsync);
	double getTime();
	int getWidth();
	int getHeight();
	std::string getTitle();

private:
	WindowProps props = { 720 , 460, "Hello OpenGL" };
	Window(WindowProps props);

};

