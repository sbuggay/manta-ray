#include <stdio.h>
#include <stdlib.h>

#include "ray.h"

vec3 color(ray r) {
    vec3 unit = vec3_unit(r.b);
    float t = 0.5 * unit.y + 1.0;
    vec3 base = vec3_mul_scalar(vec3_create(1.0, 1.0, 1.0), (1.0 - t));
    vec3 diff = vec3_mul_scalar(vec3_create(0.5, 0.7, 1.0), t);
    return vec3_add(base, diff);
}

int main(int argc, char *argv[]) {

    vec3 a = vec3_create(5, 5, 5);
    vec3 b = vec3_create(2, 2, 1);
    vec3 c = vec3_add(a, b);

    vec3 lower_left_corner = vec3_create(-2.0, -1.0, -1.0);
    vec3 horizontal = vec3_create(4.0, 0.0, 0.0);
    vec3 vertical = vec3_create(0.0, 2.0, 0.0);
    vec3 origin = vec3_create(0.0, 0.0, 0.0);

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

