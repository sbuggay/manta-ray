#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ray.h"

/**
 * @brief 
 * 
 * @param center 
 * @param radius 
 * @param r 
 * @return int 
 */
int hit_sphere(vec3 center, float radius, ray r) {
    vec3 oc = vec3_sub(r.a, center);
    float a = vec3_dot(r.b, r.b);
    float b = 2.0 * vec3_dot(oc, r.b);
    float c = vec3_dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return -1.0;
    }
    else {
        return (-1.0 * b - sqrt(discriminant)) / (2.0 * a);
    }
}

/**
 * @brief 
 * 
 * @param r 
 * @return vec3 
 */
vec3 color(ray r) {
    if (hit_sphere(vec3_create(0, 0, -1), 0.5, r)) {
        return vec3_create(1, 0, 0);
    }
    vec3 unit = vec3_unit(r.b);
    float t = 0.5 * unit.y + 1.0;
    vec3 base = vec3_mul_scalar(vec3_create(1.0, 1.0, 1.0), (1.0 - t));
    vec3 diff = vec3_mul_scalar(vec3_create(0.5, 0.7, 1.0), t);
    return vec3_add(base, diff);
}

int main(int argc, char *argv[]) {
    // Viewport vectors
    vec3 lower_left_corner = vec3_create(-2.0, -1.0, -1.0);
    vec3 horizontal = vec3_create(4.0, 0.0, 0.0);
    vec3 vertical = vec3_create(0.0, 2.0, 0.0);
    vec3 origin = vec3_create(0.0, 0.0, 0.0);

    // Viewport dimensions
    int nx = 200;
    int ny = 100;
    int i, j;

    printf("P3\n%d %d\n255\n", nx, ny);
    for (j = ny - 1; j >= 0; j--) {
        for (i = 0; i < nx; i++) {
            float u = (float) i / (float) nx;
            float v = (float) j / (float) ny;

            ray r = ray_create(origin, vec3_add(vec3_add(lower_left_corner, vec3_mul_scalar(horizontal, u)), vec3_mul_scalar(vertical, v)));
            vec3 col = color(r);
            int ir = (int) 255.99 * col.x;
            int ig = (int) 255.99 * col.y;
            int ib = (int) 255.99 * col.z;
            printf("%d %d %d\n", ir, ig, ib);
        }
    }

    return 0;
}

