#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sphere.h"

/**
 * @brief 
 * 
 * @param r 
 * @return vec3 
 */
vec3 color(ray r) {
    float t = hit_sphere(sphere_create(vec3_create(0, 0, -1), 0.5), r);
    if (t > 0.0) {
        vec3 N = vec3_unit(vec3_sub(ray_point(r, t), vec3_create(0, 0, -1)));
        return vec3_mul_scalar(vec3_create(N.x + 1, N.y + 1, N.z + 1), 0.5);
    }
    vec3 unit = vec3_unit(r.b);
    t = 0.5 * unit.y + 1.0;
    vec3 base = vec3_mul_scalar(vec3_create(1.0, 1.0, 1.0), (1.0 - t));
    vec3 diff = vec3_mul_scalar(vec3_create(0.5, 0.7, 1.0), t);
    return vec3_div(base, diff);
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
    int ns = 100;
    int i, j, s;

    printf("P3\n%d %d\n255\n", nx, ny);
    for (j = ny - 1; j >= 0; j--) {
        for (i = 0; i < nx; i++) {
            
            vec3 col = vec3_create(0, 0, 0);
            for (s = 0; s < ns; s++) {
                float u = (float) (i + drand48()) / (float) nx;
                float v = (float) (j + drand48()) / (float) ny;
                ray r = ray_create(origin, vec3_add(vec3_add(lower_left_corner, vec3_mul_scalar(horizontal, u)), vec3_mul_scalar(vertical, v)));
                col = vec3_add(col, color(r));
            }
            col = vec3_div_scalar(col, ns);
            int ir = (int) 255.99 * col.x;
            int ig = (int) 255.99 * col.y;
            int ib = (int) 255.99 * col.z;
            printf("%d %d %d\n", ir, ig, ib);
        }
    }

    return 0;
}

