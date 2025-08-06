#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "core/entityManager.h"

typedef struct {
    char * name;
    EntityId id;
}EntityData;

unsigned entityNumber = 0;
EntityData entityArray[MAX_ENTITY]; 

EntityId new_entity(char * name);
void free_entity(EntityId EntityId);
bool isEntityEmpty(EntityData * entityData);


/// @brief Create a new Entity
/// @param name of the entity. Owner is given
/// @return ID of newly created entity
EntityId new_entity(char * name) {
    if(entityNumber >= MAX_ENTITY) {
        fprintf(stderr, "Too much entity was created");
        exit(EXIT_FAILURE);
    }
    for(unsigned index = 0; index < MAX_ENTITY; index++) {
        EntityData * entityData = &entityArray[index];
        if(isEntityEmpty(entityData)){
            entityData->name = name;
            entityData->id = index;
            entityNumber++;
            return (EntityId)index;
        }
    }
}

/// @brief Free from memory an entity
/// @param entityId 
void free_entity(EntityId entityId){
    EntityData entityData = entityArray[entityId];
    if(entityData.name != NULL) {
        free(entityData.name);
        entityData.name = NULL;
    }
    return;
}

/// @brief Return true if the given entityData is empty
/// @param entityData 
/// @return bool
bool isEntityEmpty(EntityData * entityData){
    return entityData->name == NULL;
}


