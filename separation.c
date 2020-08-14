#include "boids.h"

void check_collision(int ref, t_boid *current, t_boid *looked, int *foundOne, float *closestDist, int *closestIndex, t_point *closestAhead)
{
  int i = 0;
  float dist;

  t_point ahead;

  ahead = current -> center;
  ahead.x += current -> dir.x * 10;
  ahead.y += current -> dir.y * 10;

  while (i < 30)
  {

      dist = two_dis(ahead, looked -> center);
      if (dist < 30 && (*foundOne == 0 || (*foundOne ==  1 && dist < *closestDist)))
      {

        *foundOne = 1;
        *closestDist = dist;
        *closestIndex = ref;
        *closestAhead = ahead;
      }
      ahead.x += current -> dir.x * 5;
      ahead.y += current -> dir.y * 5;

      i++;
  }

}

void	separation(t_boid *current, t_boid **array, int index)
{
  int i;
  int foundOne;
  int closestIndex;
  float closestDist;

  t_point closestAhead;
  t_point avoidForce;

  i = 0;
  foundOne = 0;
  closestDist = 0;
  while (i < current->inRange)
  {
    check_collision(i, current, array[i], &foundOne, &closestDist, &closestIndex, &closestAhead);
    i++;
  }
  if (!foundOne)
  {
    //array[index] -> avoidForce.x = 0;
    //array[index] -> avoidForce.y = 0;

    if (current -> avoidForce.x > 0)
      current -> avoidForce.x = (current -> avoidForce.x - 0.025 >= 0) ? current -> avoidForce.x - 0.025 : 0;
    if (current -> avoidForce.y > 0)
      current -> avoidForce.y = (current -> avoidForce.y - 0.025 >= 0) ? current -> avoidForce.y - 0.025 : 0;

    if (current -> avoidForce.x < 0)
      current -> avoidForce.x = (current -> avoidForce.x + 0.025 <= 0) ? current -> avoidForce.x + 0.025 : 0;
    if (current -> avoidForce.y < 0)
      current -> avoidForce.y = (current -> avoidForce.y + 0.025 <= 0) ? current -> avoidForce.y + 0.025 : 0;

  }
  if (foundOne)
  {
    avoidForce.x = (closestAhead.x - array[closestIndex] -> center.x);
    avoidForce.y = (closestAhead.y - array[closestIndex] -> center.y);
    normalize(&avoidForce);
    avoidForce.x *= 0.025;
    avoidForce.y *= 0.025;
    current -> avoidForce.x += avoidForce.x;
    current -> avoidForce.y += avoidForce.y;

    current -> dir.x += avoidForce.x;
    current -> dir.y += avoidForce.y;

  }
}
