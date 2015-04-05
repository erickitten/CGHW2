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

        if(tok == "#"){



        }else if(""){


        }
    }


}





