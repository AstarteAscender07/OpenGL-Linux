#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void processInput(GLFWwindow * window);

int main(){
    
    if(!glfwInit())
    {
        std::cout<<"Glfw Initialization is Failed"<<std::endl;
        return -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LINUX OPENGL TESTING",NULL,NULL);
    if(window == NULL)
    {
        std::cout<<"Window Initalization Failed"<<std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout<<"Failed to Initialize GLAD"<<std::endl;
        return -1;
    }
    
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.5f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
