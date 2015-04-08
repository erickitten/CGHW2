#include "worldview.h"

#include <glm/glm.hpp>
#include <vector>
#include "objmash.h"

using namespace glm;


void WorldView::bufMultiplyBy(mat4 mat){
    int i;
    for(i=0;i<vertexBuf.size();i++){
        vertexBuf[i] = vec3(vec4(vertexBuf[i],1.0) * mat);
    }
}

void WorldView::copyToBuf(){
    int i,j,k;
    int frame_v = 0;
    int frame_f = 0;
    for(i=0;i<attObj.size();i++){
        for(j=0;j<attObj[i].vertex.size();j++){
            vertexBuf[frame_v +j] = attObj[i].vertex[j];
        }
        for(k=0;k<attObj[i].surface.size();k++){
            //
            surfaceBuf[frame_f +k] = frame_v + attObj[i].surface[k];
        }
        frame_v += j;
        frame_f += k;
    }
}

void doModelView(){


}

void WorldView::attach(ObjMash & obj){
    attObj.push_back(obj);
}

