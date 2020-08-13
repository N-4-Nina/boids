#include "boids.h"

float two_dis(t_point firstPoint, t_point secondPoint)
{
   return (sqrt(pow(secondPoint.x - firstPoint.x, 2) + pow(secondPoint.y - firstPoint.y, 2) * 1.0));
}

void check_collision(t_boid *looking, t_boid *looked, int *foundOne, float *closestDist, int *closestId, t_point *closestAhead)
{
  int i = 0;
  float dist;

  t_point ahead;

  ahead = looking -> center;
  ahead.x += looking -> dir.x * 10;
  ahead.y += looking -> dir.y * 10;

  while (i < 30)
  {
      dist = two_dis(ahead, looked -> center);
      if (dist < 30 && (*foundOne == 0 || (*foundOne ==  1 && dist < *closestDist)))
      {
        *foundOne = 1;
        *closestDist = dist;
        *closestId = looked -> id;
        *closestAhead = ahead;
      }
      ahead.x += looking -> dir.x * 5;
      ahead.y += looking -> dir.y * 5;
      i++;
  }
}

void	collision_avoidance(t_boid **array, int number, int index)
{
  int i;
  int foundOne;
  int closestId;
  float closestDist;

  t_point closestAhead;
  t_point avoidForce;

  i = 0;
  foundOne = 0;
  closestDist = 0;

  while (i < number)
  {
    if (i != index)
    {
      check_collision(array[index], array[i], &foundOne, &closestDist, &closestId, &closestAhead);
    }
    i++;
  }
  if (!foundOne)
  {
    //array[index] -> avoidForce.x = 0;
    //array[index] -> avoidForce.y = 0;

    if (array[index] -> avoidForce.x > 0)
      array[index] -> avoidForce.x = (array[index] -> avoidForce.x - 0.050 >= 0) ? array[index] -> avoidForce.x - 0.050 : 0;
    if (array[index] -> avoidForce.y > 0)
      array[index] -> avoidForce.y = (array[index] -> avoidForce.y - 0.050 >= 0) ? array[index] -> avoidForce.y - 0.050 : 0;

    if (array[index] -> avoidForce.x < 0)
      array[index] -> avoidForce.x = (array[index] -> avoidForce.x + 0.050 <= 0) ? array[index] -> avoidForce.x + 0.050 : 0;
    if (array[index] -> avoidForce.y < 0)
      array[index] -> avoidForce.y = (array[index] -> avoidForce.y + 0.050 <= 0) ? array[index] -> avoidForce.y + 0.050 : 0;

    array[index] -> direction = atan2(array[index] -> dir.y + array[index] -> avoidForce.y, array[index] -> dir.x + array[index] -> avoidForce.x);
  }
  else
  {
    avoidForce.x = (closestAhead.x - array[closestId] -> center.x);
    avoidForce.y = (closestAhead.y - array[closestId] -> center.y);
    normalize(&avoidForce);
    avoidForce.x *= 0.025;
    avoidForce.y *= 0.025;
    array[index] -> avoidForce.x += avoidForce.x;
    array[index] -> avoidForce.y += avoidForce.y;

    array[index] -> direction = atan2(array[index] -> dir.y + array[index] -> avoidForce.y, array[index] -> dir.x + array[index] -> avoidForce.x);
  }
}
