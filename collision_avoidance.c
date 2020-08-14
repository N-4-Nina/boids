#include "boids.h"

void check_collision(int ref, t_boid *looking, t_boid *looked, int *foundOne, float *closestDist, int *closestIndex, t_point *closestAhead)
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
        *closestIndex = ref;
        *closestAhead = ahead;
      }
      ahead.x += looking -> dir.x * 5;
      ahead.y += looking -> dir.y * 5;

      i++;
  }

}

void	collision_avoidance(t_boid *looking, t_boid **array, int index)
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
  while (i < looking->inRange)
  {
    check_collision(i, looking, array[i], &foundOne, &closestDist, &closestIndex, &closestAhead);
    i++;
  }
  if (!foundOne)
  {
    //array[index] -> avoidForce.x = 0;
    //array[index] -> avoidForce.y = 0;

    if (looking -> avoidForce.x > 0)
      looking -> avoidForce.x = (looking -> avoidForce.x - 0.025 >= 0) ? looking -> avoidForce.x - 0.025 : 0;
    if (looking -> avoidForce.y > 0)
      looking -> avoidForce.y = (looking -> avoidForce.y - 0.025 >= 0) ? looking -> avoidForce.y - 0.025 : 0;

    if (looking -> avoidForce.x < 0)
      looking -> avoidForce.x = (looking -> avoidForce.x + 0.025 <= 0) ? looking -> avoidForce.x + 0.025 : 0;
    if (looking -> avoidForce.y < 0)
      looking -> avoidForce.y = (looking -> avoidForce.y + 0.025 <= 0) ? looking -> avoidForce.y + 0.025 : 0;

    looking -> direction = atan2(looking -> dir.y + looking -> avoidForce.y, looking -> dir.x + looking -> avoidForce.x);
  }
  else
  {
    avoidForce.x = (closestAhead.x - array[closestIndex] -> center.x);
    avoidForce.y = (closestAhead.y - array[closestIndex] -> center.y);
    normalize(&avoidForce);
    avoidForce.x *= 0.025;
    avoidForce.y *= 0.025;
    looking -> avoidForce.x += avoidForce.x;
    looking -> avoidForce.y += avoidForce.y;

    looking -> direction = atan2(looking -> dir.y + looking -> avoidForce.y, looking -> dir.x + looking -> avoidForce.x);
  }
}
