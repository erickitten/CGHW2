#include <GLFW/glfw3.h>
#include <cstdlib>
#include <string>
#include <vector>
#include "glwrapper.h"
#include "objmash.h"
#include "worldview.h"
#include "makemat.h"

using namespace std;

static void render();

int main(int argc,char *argv[])
{
    ObjMash o;
    WorldView view;

    if(argc > 1){
        o.readFromFile(string(argv[1]));
    }else{
        return EXIT_FAILURE;
    }

    view.attach(o);

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
    view.drawScreen();
}
