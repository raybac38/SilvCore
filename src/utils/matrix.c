#include "utils/matrix.h"

Vector3 matrix_multiply_3x3(Matrix3 matrix, Vector3 vector){
    return (Vector3){
        matrix[0] * vector.x + matrix[3] * vector.y + matrix[6] * vector.z,
        matrix[1] * vector.x + matrix[4] * vector.y + matrix[7] * vector.z,
        matrix[2] * vector.x + matrix[5] * vector.y + matrix[8] * vector.z
    };
}