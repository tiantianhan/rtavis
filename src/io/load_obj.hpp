#ifndef LOAD_OBJ
#define LOAD_OBJ

#include <string>
#include "tiny_obj_loader.h"

tinyobj::ObjReader getReader(std::string inputfile);
int tiny_obj_loader_test(std::string inputfile);

#endif