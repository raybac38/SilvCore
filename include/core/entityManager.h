#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#define MAX_ENTITY 64

typedef unsigned int EntityId;

EntityId new_entity(char * name);
void free_entity(EntityId EntityId);

#endif