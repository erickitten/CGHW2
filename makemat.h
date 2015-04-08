#ifndef _MAKEMAT_H
#define _MAKEMAT_H

#include <glm/glm.hpp>

namespace MakeMat{
    glm::mat4 modelView(glm::vec3 pos,glm::vec3 norm,glm::vec3 viewup = glm::vec3(0.0,1.0,0.0));


}
#endif
