/* Ask for an OpenGL Core Context */
#define GLFW_INCLUDE_GLCOREARB
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void processRender(GLFWwindow *window);

// settings
const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main(int argc, char **argv)
{
    GLFWwindow * window;

    /* Initialize the GLFW library */
    if (!glfwInit())
    {
        std::cout << "For some reason couldn't initialize the GLFW library." << std::endl;
        return -1;
    }

    /* Configuration of GLFW Window */
    #ifdef __APPLE__
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #else
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #endif

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);
    
    /* Check for initialization of window status */
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }  

    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

    while(!glfwWindowShouldClose(window))
    {
        // Handle Input
        processInput(window);

        // Handle Render
        processRender(window);

        // Swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /* Terminates the GLFW Library */
    glfwTerminate();
    return 0;
}

/* Process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly */
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void processRender(GLFWwindow *window)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


/* Whenever the window size changed (by OS or user resize) this callback function executes */
void framebuffer_size_callback(GLFWwindow* window, int width, int height) { 
    glViewport(0,0,width,height); 
}


