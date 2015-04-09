#ifndef _MAKEMAT_H
#define _MAKEMAT_H

#include <glm/glm.hpp>

namespace MakeMat{
    glm::mat4 modelView(glm::vec3 pos,glm::vec3 norm,glm::vec3 viewup = glm::vec3(0.0,1.0,0.0));
    glm::mat4 othoNorm(glm::vec3 min = glm::vec3(-2.0,-2.0,-2.0),glm::vec3 max = glm::vec3(2.0,2.0,2.0));
    glm::mat4 othoProj();

    glm::mat4 translation(glm::vec3 diff);
    glm::mat4 translation(glm::vec3 diff);
    glm::mat4 scale(glm::vec3 s);
    glm::mat4 rotation(char axis,float deg);
}
#endif
