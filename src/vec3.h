#ifndef VEC3H
#define VEC3H

/**
 * @brief 
 * 
 */
typedef struct {
    double x;
    double y;
    double z;
} vec3;

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param z 
 * @return vec3 
 */
vec3 vec3_create(double x, double y, double z);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return vec3 
 */
vec3 vec3_add(vec3 a, vec3 b);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return vec3 
 */
vec3 vec3_sub(vec3 a, vec3 b);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return vec3 
 */
vec3 vec3_mul(vec3 a, vec3 b);

vec3 vec3_div(vec3 a, vec3 b);

vec3 vec3_mul_scalar(vec3 a, double t);

vec3 vec3_div_scalar(vec3 a, double t);

float vec3_dot(vec3 a, vec3 b);

vec3 vec3_cross(vec3 a, vec3 b);

double vec3_length(vec3 a);

vec3 vec3_unit(vec3 a);

#endif