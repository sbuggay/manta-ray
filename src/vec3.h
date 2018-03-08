#ifndef VEC3H
#define VEC3H

/**
 * @brief 
 * 
 */
typedef struct {
    float x;
    float y;
    float z;
} vec3;

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param z 
 * @return vec3 
 */
vec3 vec3_create(float x, float y, float z);

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

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return vec3 
 */
vec3 vec3_div(vec3 a, vec3 b);

/**
 * @brief 
 * 
 * @param a 
 * @param t 
 * @return vec3 
 */
vec3 vec3_mul_scalar(vec3 a, float t);

/**
 * @brief 
 * 
 * @param a 
 * @param t 
 * @return vec3 
 */
vec3 vec3_div_scalar(vec3 a, float t);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return float 
 */
float vec3_dot(vec3 a, vec3 b);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return vec3 
 */
vec3 vec3_cross(vec3 a, vec3 b);

/**
 * @brief 
 * 
 * @param a 
 * @return float 
 */
float vec3_length(vec3 a);

/**
 * @brief 
 * 
 * @param a 
 * @return vec3 
 */
vec3 vec3_unit(vec3 a);

#endif