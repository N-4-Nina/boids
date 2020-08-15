#include "boids.h"

void check_collision(int ref, t_boid *current, t_boid *looked, int *foundOne, float *closestDist, int *closestIndex, t_point *closestAhead)
{
  int i = 0;
  float dist;


  dist = two_dis(current->center, looked -> center);
  if (dist < 30 && (*foundOne == 0 || (*foundOne ==  1 && dist < *closestDist)))
  {

    *foundOne = 1;
    *closestDist = dist;
    *closestIndex = ref;
    //*closestAhead = ahead;
  }


}

void	separation(t_boid *current, t_boid **nearby, int index)
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
    check_collision(i, current, nearby[i], &foundOne, &closestDist, &closestIndex, &closestAhead);
    i++;
  }
  /*if (!foundOne)
  {

    if (current -> avoidForce.x > 0)
      current -> avoidForce.x = (current -> avoidForce.x - 0.025 >= 0) ? current -> avoidForce.x - 0.025 : 0;
    if (current -> avoidForce.y > 0)
      current -> avoidForce.y = (current -> avoidForce.y - 0.025 >= 0) ? current -> avoidForce.y - 0.025 : 0;

    if (current -> avoidForce.x < 0)
      current -> avoidForce.x = (current -> avoidForce.x + 0.025 <= 0) ? current -> avoidForce.x + 0.025 : 0;
    if (current -> avoidForce.y < 0)
      current -> avoidForce.y = (current -> avoidForce.y + 0.025 <= 0) ? current -> avoidForce.y + 0.025 : 0;

  }*/
  if (foundOne)
  {
    avoidForce.x = (current -> center.x - nearby[closestIndex] -> center.x);
    avoidForce.y = (current -> center.y - nearby[closestIndex] -> center.y);
    normalize(&avoidForce);
    avoidForce.x *= 0.050;
    avoidForce.y *= 0.050;

    //current -> avoidForce.x += avoidForce.x;
    //current -> avoidForce.y += avoidForce.y;

    current -> dir.x += avoidForce.x;
    current -> dir.y += avoidForce.y;

  }
}
