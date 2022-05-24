#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>


int main(){

    GLFWwindow* window = glfwCreateWindow( 1080, 720, "Hello OpenGL", NULL, NULL);
    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwMakeContextCurrent(window);

    if(window==NULL)
    {
        std::cout<<window<<std::endl;
        std::cout<<"ERROR : Window Not Initialise"<<std::endl;
    }

    while(glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents(); 
    }

    glfwTerminate();
    return 0;
}
