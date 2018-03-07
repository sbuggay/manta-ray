#include "ray.h"

ray ray_create(vec3 a, vec3 b) {
    return (ray) {a, b};
}

vec3 ray_point(ray a, float t) {
    return vec3_add(a.a, vec3_mul_scalar(a.b, t));
}
