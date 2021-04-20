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







void readSettings(std::map<std::string,struct setting> &settings,std::string fileName);
void writeSettings(std::map<std::string,struct setting> settings,std::string fileName);
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

    readSettings(settings,"settings.txt");
    writeSettings(settings,"settings.txt");



    if (!glfwInit()) throw "Error: GLFW could not initialize.";

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* vidMode = glfwGetVideoMode(primaryMonitor);
    GLFWwindow* window;
    std::string title = "Window";

    if(settings["fullscreen"].current == "true"){
        glfwWindowHint(GLFW_RED_BITS, vidMode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, vidMode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, vidMode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, vidMode->refreshRate);
        window = glfwCreateWindow(vidMode->width,vidMode->height,title.c_str(),primaryMonitor, NULL);
    }
    else{
        window = glfwCreateWindow(std::atoi(settings["width"].current.c_str()),std::atoi(settings["height"].current.c_str()),title.c_str(),NULL, NULL);
    }

    
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

void readSettings(std::map<std::string,struct setting> &settings,std::string fileName){

    std::fstream file;
    std::string dir = getexepath().substr(0,getexepath().find_last_of("/\\")) + "/";
    std::string path = dir + fileName;

    file.open(path,std::fstream::in);

    std::string line;

    std::string key;
    std::string value;

    int index;

    while(std::getline(file,line)){
        index = line.find('=',0);
        key = line.substr(0,index);
        value = line.substr(index + 1 ,line.length()-(index+1));
        std::cout << key << " : " << value << std::endl;
        settings[key].current = value;
    }
    file.close();
}



void writeSettings(std::map<std::string,struct setting> settings,std::string fileName){

    std::fstream file;
    std::string dir = getexepath().substr(0,getexepath().find_last_of("/\\")) + "/";
    std::string path = dir + fileName;

    file.open(path,std::fstream::out);

    for(const auto& pair : settings ){
        std::string line = pair.first + "=" + pair.second.current;
        file << line;
        file << std::endl;
    }
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
