#include "boids.h"

void normalize(t_point *vector)
{
    float w = sqrt(vector->x * vector->x + vector->y * vector->y);
    vector->x /= w;
    vector->y /= w;
}
