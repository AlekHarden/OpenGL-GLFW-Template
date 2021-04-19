#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <GL/glew.h> //test order
#include <GLFW/glfw3.h>
#include <string>

class Display{

    private:
        GLFWmonitor* mPrimaryMonitor;
        const GLFWvidmode* mDisplayMode;
        GLFWwindow* mWindow;

    public:
        Display(std::string title);
        GLFWwindow* getWindow();












};


#endif
