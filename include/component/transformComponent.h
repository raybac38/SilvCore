#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <stdbool.h>

typedef struct {
    float positionX;
    float positionY;
    float positionZ;

    float rotationX;
    float rotationY;
    float rotationZ;

    float scaleX;
    float scaleY;
    float scaleZ;

    bool isStatic;    
} TransformComponentData;


#endif