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

    //Texture id 
    unsigned int texture;

    //For getting the texture
    int width, height, nrChannels;
    unsigned char* data = nullptr;

    //Texture Border Color
    float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };

    //camera stuffs

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);



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

    std::string vertex_loc = "./asset/shader/vertex.shader";
    std::string frag_loc = "./asset/shader/fragment.shader";

    Shader our_shader = Shader::Create(&vertex_loc, &frag_loc);

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

    VAO vao = VAO::Create();

    vao.bind();
    vao.LinkVBO(vbo, 0, 3, (void*)(0));
    vao.LinkVBO(vbo, 1, 3, (void*)(3 * sizeof(float)));
    vao.LinkVBO(vbo, 2, 2, (void*)(6 * sizeof(float)));
    our_shader.use();

    //coordination system

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    our_shader.setMatrix4("model", model);


    glm::mat4 view = glm::mat4(1.0f);
    // note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    our_shader.setMatrix4("view", view);

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    our_shader.setMatrix4("projection", projection);

    /* Loop until the user closes the window */
    while (!window.isRunning())
    {
        glClearColor((float)0.3, (float)0.3, (float)0.3,(float) 1.0);
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        vao.bind();
        ebo.bind();

        glBindTexture(GL_TEXTURE_2D, texture);
        
        our_shader.use();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        window.ClearScreen();
    }
    vao.Destroy();
    vbo.Destroy();
    ebo.Destroy();
    our_shader.Destroy();
    window.Destroy();
    return 0;
}
