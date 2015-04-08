#include <GLFW/glfw3.h>
#include <cstdlib>
#include <string>
#include <vector>
#include "glwrapper.h"
#include "objmash.h"

using namespace std;

static void render();

int main(int argc,char *argv[])
{
    ObjMash o;
    if(argc > 1){
        o.readFromFile(string(argv[2]));
    }else{

    }
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(500, 500, "CGHW2", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        render();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}

static void render()
{
    GLWrapper::clearScreen();
    GLWrapper::drawLine(0,0,0.5,0.5);
    GLWrapper::drawLine(-1,-0.9,1,-0.9);

}
