#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <Display.hpp>





int main(void){


    Display display("OpenGL");
    GLFWwindow* window = display.getWindow();


     
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