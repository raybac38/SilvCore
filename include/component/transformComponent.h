#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <stdbool.h>
#include "utils/vector3.h"

typedef struct {
    bool enabled;

    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

    bool isStatic;    
} TransformComponent;


#endif