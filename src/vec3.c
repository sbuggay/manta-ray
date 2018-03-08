#include "vec3.h"

#include <math.h>

vec3 vec3_create(float x, float y, float z) {
    return (vec3) {x, y, z};
}

vec3 vec3_add(vec3 a, vec3 b) {
    return (vec3) {a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3 vec3_sub(vec3 a, vec3 b) {
    return (vec3) {a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3 vec3_mul(vec3 a, vec3 b) {
    return (vec3) {a.x * b.x, a.y * b.y, a.z * b.z};
}

vec3 vec3_div(vec3 a, vec3 b) {
    return (vec3) {a.x / b.x, a.y / b.y, a.z / b.z};
}

vec3 vec3_mul_scalar(vec3 a, float t) {
    return (vec3) {a.x * t, a.y * t, a.z * t};
}

vec3 vec3_div_scalar(vec3 a, float t) {
    return (vec3) {a.x / t, a.y / t, a.z / t};
}

float vec3_dot(vec3 a, vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 vec3_cross(vec3 a, vec3 b) {
    return (vec3) {
        a.y * b.z - a.z * b.y,
        (-1 * a.x * b.z) - a.z * b.x,
        a.x * b.y - a.y * b.x
    };
}

float vec3_length(vec3 a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

vec3 vec3_unit(vec3 a) {
    return vec3_div_scalar(a, 1.0 / vec3_length(a));
}