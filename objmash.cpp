#include "objmash.h"

#include <iostream>
#include <fstream>

void ObjMash::readFromFile(string fn){
    fstream mashFile;
    string line,tok;
    istringstream iss;

    mashFile.open(fn,ios::in);
    
    while(getline(fn,line)){
        iss.str(line);
        iss >> tok;

        if(tok == "v"){
            float tmp;
            iss >> tmp; //x
            v.push_back(tmp);
            iss >> tmp; //y
            v.push_back(tmp);
            iss >> tmp; //z
            v.push_back(tmp);
        }else if(tok == "f"){
            int tmp;
            vector<int> s;
            while(iss >> tmp){
                s.push_back(tmp);
            }
            f.push_back(s);
        }else if(tok == "#"){
            continue;
        }else if(tok == "o"){
            iss >> name;
        }
    }

}





