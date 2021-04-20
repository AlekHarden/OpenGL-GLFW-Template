#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <map>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#include <limits.h>
#include <unistd.h>
#endif







void readSettings(std::map<std::string,struct setting>,std::string fileName);
std::string getexepath();


struct setting{
    std::string preset;
    std::string current;
};


int main(){

    std::map<std::string,struct setting> settings;
    settings.insert( std::pair<std::string,struct setting>("fullscreen",{"false","false"}));
    settings.insert( std::pair<std::string,struct setting>("width",{"854","854"}));
    settings.insert( std::pair<std::string,struct setting>("height",{"480","480"}));


    std::cout << "----" << std::endl;
    readSettings(settings,"settings.txt");



    if (!glfwInit()) throw "Error: GLFW could not initialize.";

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* vidMode = glfwGetVideoMode(primaryMonitor);

    GLFWwindow* window = glfwCreateWindow(300,300,"Window",NULL, NULL);


    
    if (!window){
        glfwTerminate();
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

void readSettings(std::map<std::string,struct setting>,std::string fileName){

    std::fstream file;
    file.open(fileName,std::fstream::out);

    std::cout << getexepath() << std::endl;

    file << "fuckmeeeeeee";

    file.close();
}



#ifdef _WIN32
std::string getexepath(){
  char result[ MAX_PATH ];
  return std::string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
}
#endif


#ifdef linux
std::string getexepath()
{
  char result[ PATH_MAX ];
  ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
  return std::string( result, (count > 0) ? count : 0 );
}
#endif
