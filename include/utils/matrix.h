#ifndef MATRIX_H
#define MATRIX_H

#include "utils/vector3.h"

typedef float Matrix4[16];
typedef float Matrix3[9];

Vector3 matrix_multiply_3x3(Matrix3 matrix, Vector3 vector);


#endif