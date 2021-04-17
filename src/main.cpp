
#include <iostream>
#include <GLFW/glfw3.h>




int main(void){




    if (!glfwInit()) throw "Error: GLFW could not initialize.";

    GLFWwindow* window = glfwCreateWindow(640,480, "Window", NULL, NULL);
    
    if (!window){
        glfwTerminate();
        return -1;
    }


    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    } 

    return 0;
}