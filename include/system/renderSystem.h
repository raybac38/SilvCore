#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <stdbool.h>

#include "core/entityManager.h"

/// @brief Init the render system
void render_system_init();

/// @brief update the render system (render all meshes)
void render_system_update();

/// @brief Add Render component to an entity
/// @param entityId entity id
/// @return succes
bool transform_add_component(EntityId entityId);

/// @brief Remove Render component to an entity
/// @param entityId entity id
/// @return succes
bool transform_remove_component(EntityId entityId);


#endif