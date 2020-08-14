#include "boids.h"

t_point average_Direction(t_boid **nearby)
{
  int i = 0;
  t_point average;
  average.x = 0;
  average.y = 0;
  while(nearby[i])
  {
    average.x += nearby[i]->dir.x;
    average.y += nearby[i]->dir.y;
    i++;
  }
  if (i == 0)
    return (average);
  average.x /= i+1;
  average.y /= i+1;
  return (average);
}

void alignment(t_boid *current, t_boid **nearby, int index)
{
  if (current->inRange == 0)
    return;

  t_point average = average_Direction(nearby);

  normalize(&average);

  current->dir.x += average.x * 0.012;
  current->dir.y += average.y * 0.012;
}
