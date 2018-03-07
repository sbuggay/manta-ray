#ifndef RAYH
#define RAYH
#include "vec3.h"

typedef struct {
    vec3 a;
    vec3 b;
} ray;

ray ray_create(vec3 a, vec3 b);
vec3 ray_point(ray a, float t);

#endif