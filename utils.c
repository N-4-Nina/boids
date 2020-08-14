#include "boids.h"

float two_dis(t_point firstPoint, t_point secondPoint)
{
   return (sqrt(pow(secondPoint.x - firstPoint.x, 2) + pow(secondPoint.y - firstPoint.y, 2) * 1.0));
}

void normalize(t_point *vector)
{
    float w = sqrt(vector->x * vector->x + vector->y * vector->y);
    vector->x /= w;
    vector->y /= w;
}
