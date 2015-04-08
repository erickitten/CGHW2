#include "makemat.h"

#include <glm/glm.hpp>

using namespace glm;

namespace MakeMat{
    mat4 modelView(vec3 pos,vec3 norm,vec3 viewup){
        vec3 v = viewup - 
               ( (dot(viewup,norm))/(dot(norm,norm)) ) * norm;
        vec3 u = cross(v,n);

        u = normailze(u);
        v = normailze(v);
        vec3 n = normailze(norm);

        //note each line = column
        mat4 R( u,0.0f
                v,0.0f
                n,0.0f
                vec(0,0,0),1);
        R = transpose(R);
        mat4 T( vec(1,0,0),0
                vec(0,1,0),0
                vec(0,0,1),0
                pos,1);
        return R * T;
    }






}




