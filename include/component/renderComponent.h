#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include "utils/vector3.h"
#include "utils/vector2.h"

typedef struct {
    unsigned vertexCount;
    Vector3 * vertices;
    Vector3 * normals;
    Vector2 * uvs;          
    unsigned indexCount;    
    unsigned * indices;     
} Mesh;

#endif