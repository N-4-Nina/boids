#include "../boids.h"

void check_collision(int ref, t_boid *current, t_boid *looked, int *foundOne, float *closestDist, int *closestIndex)
{
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

void	separation(t_boid *current, t_boid **nearby)
{
  int i;
  int foundOne;
  int closestIndex;
  float closestDist;

  t_point avoidForce;

  i = 0;
  foundOne = 0;
  closestDist = 0;
  while (i < current->inRange)
  {
    check_collision(i, current, nearby[i], &foundOne, &closestDist, &closestIndex);
    i++;
  }
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
