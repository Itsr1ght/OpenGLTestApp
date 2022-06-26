#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb_image.h"
#include "Window.h"
#include "Shader.h"
#include "Buffer.h"



int main()
{

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  

    //vertex array object
    unsigned int VAO = 0;


    //Texture id 
    unsigned int texture;

    //For getting the texture
    int width, height, nrChannels;
    unsigned char* data = nullptr;

    //Texture Border Color
    float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };



    //vertices for triangle
    float vertices[] = {
        // positions         // colors
        0.5f,  0.5f, 0.0f ,  1.0f, 0.0f, 0.0f,   1.0f,1.0f,
        0.5f, -0.5f, 0.0f ,  0.0f, 1.0f, 0.0f,   1.0f,0.0f,
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f,0.0f,
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,  0.0f,1.0f
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    Window window = Window::Create({720 , 480, "Hello OpenGL"});

    glEnable(GL_DEPTH_TEST);

    VBO vbo = VBO::Create(vertices, sizeof(vertices));

    EBO ebo = EBO::Create(indices, sizeof(indices));


    Shader our_shader("./asset/shader/vertex.shader", "./asset/shader/fragment.shader");

    /*Texture Stuff*/

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    data = stbi_load("./asset/texture/container.jpg", &width, &height, &nrChannels, 0);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    ////////// VAO //////////////
    //For generating array object
    glGenVertexArrays(1, &VAO);
    //For Binding Array Object
    glBindVertexArray(VAO);
    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    std::cout << glGetString(GL_VERSION) << std::endl;
    our_shader.use();

    /* Loop until the user closes the window */
    while (!window.isRunning())
    {
        glClearColor((float)0.3, (float)0.3, (float)0.3,(float) 1.0);
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(VAO);
        
        ebo.bind();

        glBindTexture(GL_TEXTURE_2D, texture);
        
        our_shader.use();        
        
        glBindVertexArray(VAO);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        window.ClearScreen();
    }
    glDeleteVertexArrays(1, &VAO);
    vbo.Destroy();
    ebo.Destroy();
    window.Destroy();
    return 0;
}