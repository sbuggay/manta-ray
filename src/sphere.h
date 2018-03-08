#ifndef SPHEREH
#define SPHEREH

#include "vec3.h"
#include "ray.h"

typedef struct {
    vec3 center;
    float radius;
} sphere;

sphere sphere_create(vec3 center, float radius);

float hit_sphere(sphere s, ray r);

#endif