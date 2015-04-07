#ifndef _OBJMASH_H
#define _OBJMASH_H

#include <string>
#include <vector>

class ObjMash{
    std::string name;
    std::vector<float> v;
    std::vector<std::vector<int>> f;

public:
    ObjMash();
    ObjMash(std::string fn);
    void readFromFile(std::string fn);    
};

#endif
