#ifndef SCENEH
#define SCENEH

#include "sphere.h"

typedef struct {
    int nSpheres; // number of spheres in the scene
    int nCubes; // number of cubes in the scene
    sphere *spheres;
} scene;

#endif