#ifndef TRANSFORM_SYSTEM_H
#define TRANSFORM_SYSTEM_H

#include <stdbool.h>

#include "utils/vector3.h"
#include "core/entityManager.h"

/// @brief Add Transform component to an entity
/// @param entityId entity id
/// @return succes
bool transform_add_component(EntityId entityId);

/// @brief Remove Transform component to an entity
/// @param entityId entity id
/// @return succes
bool transform_remove_component(EntityId entityId);

/// @brief Translate the given entity
/// @param entityId entity id
/// @param translate translation vector
/// @return succes
bool transform_translate(EntityId entityId, Vector3 translate);

/// @brief Set entity position
/// @param entityId entity id
/// @param newPosition position
/// @return succes
bool transform_set_position(EntityId entityId, Vector3 newPosition);

/// @brief Get entity current position
/// @param entityId entity id
/// @return entity position if succes
Vector3 transform_get_position(EntityId entityId);

/// @brief Rotate the given entity
/// @param entityId entity id
/// @param translate rotation vector
/// @return succes
bool transform_rotate(EntityId entityId, Vector3 rotate);

/// @brief Set entity rotation
/// @param entityId entity id
/// @param newPosition rotation
/// @return succes
bool transform_set_rotation(EntityId entityId, Vector3 newRotation);

/// @brief Get entity current rotation
/// @param entityId entity id
/// @return entity rotation if succes
Vector3 transform_get_rotation(EntityId entityId);

/// @brief Scale the given entity
/// @param entityId entity id
/// @param translate scaling vector
/// @return succes
bool transform_scale(EntityId entityId, Vector3 scale);

/// @brief Set entity scale
/// @param entityId entity id
/// @param newPosition scale
/// @return succes
bool transform_set_scale(EntityId entityId, Vector3 newScale);

/// @brief Get entity current scale
/// @param entityId entity id
/// @return entity scale if succes
Vector3 transform_get_scale(EntityId entityId);

/// @brief Set static to an entity
/// @param entityId entity id
/// @param isStatic static value
/// @return succes
bool transform_set_static(EntityId entityId, bool isStatic);

/// @brief Is the entity static 
/// @param entityId entity id
/// @return return 
bool transform_is_static(EntityId entityId);



#endif
