#include "system/transformSystem.h"
#include "core/entityManager.h"
#include "component/transformComponent.h"
#include "transformSystem.h"
#include "utils/matrix.h"
#include <math.h>

#include <stdio.h>
#include <stdlib.h>

static TransformComponent * transformComponentArray;

void transform_system_init(){
    transformComponentArray = calloc(sizeof(TransformComponent),  MAX_ENTITY);
    if(transformComponentArray == NULL){
        fprintf(stderr, "Transform systeme wasn't able to init");
    }
}

void transform_system_clean(){
    if(transformComponentArray != NULL){
        free(transformComponentArray);
        transformComponentArray = NULL;
    }
}

static inline TransformComponent * get_transform_component_ptr(EntityId entityId){
    return transformComponentArray + entityId; 
}

bool transform_add_component(EntityId entityId)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 

    if (transformComponentPtr->enabled){
        return false;
    }
    
    transformComponentPtr->enabled = true;
    transformComponentPtr->isStatic = false;

    transformComponentPtr->position.x = 0;
    transformComponentPtr->position.y = 0;
    transformComponentPtr->position.z = 0;
    
    transformComponentPtr->rotation.x = 0;
    transformComponentPtr->rotation.y = 0;
    transformComponentPtr->rotation.z = 0;

    transformComponentPtr->scale.x = 0;
    transformComponentPtr->scale.y = 0;
    transformComponentPtr->scale.z = 0;

    return true;
}

bool transform_remove_component(EntityId entityId)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 
    transformComponentPtr->enabled = false;
    return true;
}

bool transform_translate(EntityId entityId, Vector3 translate)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 
    if(!transformComponentPtr->enabled) return false;
    transformComponentPtr->position.x += translate.x;
    transformComponentPtr->position.y += translate.y;
    transformComponentPtr->position.z += translate.z;
    return true;
}

bool transform_set_position(EntityId entityId, Vector3 newPosition)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 
    if(!transformComponentPtr->enabled) return false;
    transformComponentPtr->position.x = newPosition.x;
    transformComponentPtr->position.y = newPosition.y;
    transformComponentPtr->position.z = newPosition.z;
    return true;
}

Vector3 transform_get_position(EntityId entityId)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 
    return transformComponentPtr->position;
}

bool transform_rotate(EntityId entityId, Vector3 rotate)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 
    if (!transformComponentPtr->enabled) return false;

    Matrix3 rotationMatrixX = {
        1, 0, 0,
        0, cosf(rotate.x), sinf(rotate.x),
        0, -sinf(rotate.x), cosf(rotate.x)
    };

    Matrix3 rotationMatrixY = {
        cosf(rotate.y), 0, -sinf(rotate.y),
        0, 1, 0,
        sinf(rotate.y), 0, cosf(rotate.y)
    };

    Matrix3 rotationMatrixZ = {
        cosf(rotate.z), sinf(rotate.z), 0,
        -sinf(rotate.z), cosf(rotate.z), 0,
        0, 0, 1
    };

    Vector3 actualRotation = transformComponentPtr->rotation;

    Vector3 rotated = matrix_multiply_3x3(rotationMatrixX, actualRotation);
    rotated = matrix_multiply_3x3(rotationMatrixY, rotated);
    rotated = matrix_multiply_3x3(rotationMatrixZ, rotated);

    transformComponentPtr->rotation = rotated;
    return true;
}


bool transform_set_rotation(EntityId entityId, Vector3 newRotation)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 
    if(!transformComponentPtr->enabled) return false;
    transformComponentPtr->rotation.x = newRotation.x;
    transformComponentPtr->rotation.y = newRotation.y;
    transformComponentPtr->rotation.z = newRotation.z;
    return true;
}

Vector3 transform_get_rotation(EntityId entityId)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 
    return transformComponentPtr->rotation;
}

bool transform_scale(EntityId entityId, Vector3 scale)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 
    if(!transformComponentPtr->enabled) return false;
    transformComponentPtr->scale.x *= scale.x;
    transformComponentPtr->scale.y *= scale.y;
    transformComponentPtr->scale.z *= scale.z;
    return true;
}

bool transform_set_scale(EntityId entityId, Vector3 newScale)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 
    if(!transformComponentPtr->enabled) return false;
    transformComponentPtr->scale.x = newScale.x;
    transformComponentPtr->scale.y = newScale.y;
    transformComponentPtr->scale.z = newScale.z;
    return true;
}

Vector3 transform_get_scale(EntityId entityId)
{
    TransformComponent * transformComponentPtr = get_transform_component_ptr(entityId); 
    return transformComponentPtr->scale;
}

bool transform_set_static(EntityId entityId, bool isStatic)
{
    return false;
}