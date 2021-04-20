#include <Display.hpp>


Display::Display(std::string title){

    if (!glfwInit()) throw "Error: GLFW could not initialize.";

    mPrimaryMonitor = glfwGetPrimaryMonitor();
    mDisplayMode = glfwGetVideoMode(mPrimaryMonitor);

    mWindow = glfwCreateWindow(mDisplayMode->width, mDisplayMode->height, title.c_str(), mPrimaryMonitor, NULL);


    
    if (!mWindow){
        glfwTerminate();
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(mWindow);

    if (glewInit() != GLEW_OK) throw "Error: GLEW could not Initialize";


}

GLFWwindow* Display::getWindow(){
    return mWindow;
}
