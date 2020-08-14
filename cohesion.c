#include "boids.h"

t_point find_Center(t_boid **nearby)
{
  int i = 0;
  t_point center;
  center.x = 0;
  center.y = 0;
  while (nearby[i])
  {
    center.x += nearby[i]-> center.x;
    center.y += nearby[i]-> center.y;
    i++;
  }
  center.x /= i+1;
  center.y /= i+1;

  return (center);
}

void cohesion(t_boid *current, t_boid **nearby, int index)
{
  if (current->inRange == 0)
    return;

  t_point center = find_Center(nearby);

  normalize(&center);

  current->dir.x += center.x * 0.012;
  current->dir.y += center.y * 0.012;
}
