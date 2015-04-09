#include "worldview.h"

#include <glm/glm.hpp>
#include <vector>
#include "objmash.h"
#include "glwrapper.h"
#include "makemat.h"

using namespace glm;
using namespace std;


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
            surfaceBuf[frame_f +k] = attObj[i].surface[k];
        }
        frame_v += j;
        frame_f += k;
    }
}



void WorldView::attach(ObjMash & obj){
    attObj.push_back(obj);
}

void WorldView::drawScreen(){
    int i,j;

    copyToBuf();
    bufMultiplyBy(MakeMat::modelView(
                vec3(0.0f,0.0f,-2.0f),vec3(0.0f,0.0f,1.0f)));
    bufMultiplyBy(MakeMat::othoNorm());
    bufMultiplyBy(MakeMat::othoProj());
    
    for(i=0;i<surfaceBuf.size();i++){
        vector<int> & curr = surfaceBuf[i];
        for(j=1;j<curr.size();j++){
            GLWrapper::drawLine(vertexBuf[curr[j-1]][0],
                    vertexBuf[curr[j-1]][1],vertexBuf[curr[j]][0],
                    vertexBuf[curr[j]][1]);
        }
    }
}
