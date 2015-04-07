#include <GLFW/glfw3.h>
#include <cmath>
#include "glwrapper.h"

#define abs(a) ((a)>=0?(a):-(a))

void GLWrapper::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void GLWrapper::drawPoint(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void GLWrapper::setPointColor(float r, float g, float b)
{
	glColor3f(r, g, b);
}

void GLWrapper::drawLine(float x1, float y1, float x2, float y2)
{
    int i;
    int samp = 250 * sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    float vecx = (x2-x1)/samp;
    float vecy = (y2-y1)/samp;
    float curx = x1;
    float cury = y1;

    for(i=0;i<samp;i++){
        drawPoint(curx,cury);
        curx += vecx;
        cury += vecy;
    }
}
