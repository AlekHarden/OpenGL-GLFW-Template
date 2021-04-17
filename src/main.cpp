#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>





int main(void){





    if (!glfwInit()) throw "Error: GLFW could not initialize.";

    GLFWmonitor *primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *vidMode = glfwGetVideoMode(primaryMonitor);

    GLFWwindow* window = glfwCreateWindow(vidMode->width, vidMode->height, "Window", primaryMonitor, NULL);


    
    if (!window){
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) throw "Error: GLEW could not Initialize";

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();


    return 0;
}