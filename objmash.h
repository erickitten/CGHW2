#ifndef _OBJMASH_H
#define _OBJMASH_H

#include <glm/glm.hpp>
#include <string>
#include <vector>

class ObjMash{
    friend class WorldView;
private:
    std::string name;
    std::vector<glm::vec3> vertex;
    std::vector<std::vector<int>> surface;

public:
    ObjMash();
    ObjMash(std::string fn);
    void readFromFile(std::string fn);
    void multiplyBy(glm::mat4 mat);
};

#endif
