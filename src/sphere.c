#include <math.h>

#include "sphere.h"

sphere sphere_create(vec3 center, float radius) {
    return (sphere) {
        center,
        radius
    };
}

float hit_sphere(sphere s, ray r) {
    // t * t * dot(b, b) + 2 * t * dot(b, a - c) + dot(a - c, a - c) - R * R = o;
    vec3 oc = vec3_sub(r.a, s.center);
    
    float a = vec3_dot(r.b, r.b);
    
    float b = 2.0 * vec3_dot(oc, r.b);
    
    float c = vec3_dot(oc, oc) - s.radius * s.radius;
    
    float discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0) {
        return -1.0;
    }
    else {
        return (-1.0 * b - sqrt(discriminant)) / (2.0 * a);
    }
}