#ifndef __OBJ_LOADER_H__
#define __OBJ_LOADER_H__

#include "Vertex.h"
#include <string>
#include <unordered_map>

struct OBJLoader
{
public:
	static void loadModel(const std::string & file_path, std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
};

#endif