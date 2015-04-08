#ifndef _WORLDVIEW_H
#define _WORLDVIEW_H

#include <glm/glm.hpp>

#include <vector>
#include "objmash.h"

class WorldView{
private:
    bool orthogonal;


    vector<ObjMash> attObj;
    vector<glm::vec3> vertexBuf;
    std::vector<std::vector<int>> surfaceBuf;


    void bufMultiplyBy(glm::mat4 mat);
    void copyToBuf();
public:
    void attach(ObjMash & obj);
    void setCamera();
    void drawScreen();
};

#endif
