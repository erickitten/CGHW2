#include "makemat.h"

#include <glm/glm.hpp>
#include <cmath>

#define _USE_MATH_DEFINES
using namespace glm;

namespace MakeMat{
    mat4 modelView(vec3 pos,vec3 norm,vec3 viewup){
        vec3 v = viewup - 
               ( (dot(viewup,norm))/(dot(norm,norm)) ) * norm;
        vec3 u = cross(v,norm);

        u = normalize(u);
        v = normalize(v);
        vec3 n = normalize(norm);

        //note each line = column
        mat4 R( vec4(u,0.0f),
                vec4(v,0.0f),
                vec4(n,0.0f),
                vec4(vec3(0.0f),1.0f));
        R = transpose(R);
        mat4 T = translation(-1.0f*pos);
        return R * T;
    }

    mat4 othoNorm(vec3 min,vec3 max){
        return scale(vec3(2.0f/max[0]-min[0],2.0f/max[1]-min[1],
                2.0f/min[2]-max[2])) * translation((min+max)/-2.0f);
    }

    mat4 othoProj(){
        mat4 m(1.0);
        m[2][2] = 0;
        return m;
    }

    mat4 translation(vec3 diff){
        mat4 m(1.0);
        m[3] = vec4(diff,1.0f);
        return m;
    }

    mat4 scale(vec3 s){
        mat4 m(1.0);
        int i;
        for(i=0;i<3;i++){
            m[i][i] = s[i];
        }
        return m;
    }

    mat4 rotation(char axis,float deg){
        mat4 m(1.0);
        float param =  deg * M_PI / 180.0f;
        float c_p = cos(param);
        float s_p = sin(param);

        if(axis == 'x'){
            m[1][1] = c_p;
            m[1][2] = s_p;
            m[2][1] = -s_p;
            m[2][2] = c_p;
        }else if(axis == 'y'){
            m[0][0] = c_p;
            m[0][2] = -s_p;
            m[2][0] = s_p;
            m[2][2] = c_p;
        }else if(axis == 'z'){
            m[0][0] = c_p;
            m[0][1] = s_p;
            m[1][0] = -s_p;
            m[1][1] = c_p;
        }
        return m;
    }
}




