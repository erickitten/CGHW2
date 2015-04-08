#include "objmash.h"

#include <glm/glm.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace glm;

ObjMash::ObjMash(){
}

ObjMash::ObjMash(string fn){
    readFromFile(fn);
}

void ObjMash::readFromFile(string fn){
    fstream mashFile;
    string line,tok;
    istringstream iss;

    mashFile.open(fn,ios::in);
    
    while(getline(mashFile,line)){
        iss.str(line);
        iss >> tok;

        if(tok == "v"){
            vec3 v(0.0);
            iss >> v[0]; //x
            iss >> v[1]; //y
            iss >> v[2]; //z
            vertex.push_back(v);
        }else if(tok == "f"){
            int tmp;
            vector<int> s;
            while(iss >> tmp){
                s.push_back(tmp);
            }
            surface.push_back(s);
        }else if(tok == "#"){
            continue;
        }else if(tok == "o"){
            iss >> name;
        }
    }
}

//for transforms
void ObjMash::multiplyBy(mat4 mat){
    int i;
    for(i=0;i<vertex.size();i++){
        vertex[i] = vec3(vec4(vertex[i],1.0) * mat);
    }
}


