#include "boids.h"

void fillInRange(int index, t_flock *f)
{
	int i = 0;
	int j = 0;

	f->boids[index]-> inRange = 0;
	while(i < f->size)
	{
		f->inRange[i] = NULL;
		i++;
	}
	i = 0;

	while(i < f->size)
	{
		if (i != index && two_dis(f->boids[i]->center, f->boids[index]->center) < 150)
		{
			//printf("boid n° %d found in range of boid n° %d \n", index, i);
			f->inRange[j] = f->boids[i];
			f->boids[index]->inRange++;
			j++;
		}
		i++;
	}
}

int	handle_EOW(t_boid **array, int i)
{
	int	r;

	r = 0;
	if (array[i] -> center.y <= 0)
	{
		array[i] -> center.y = SCREEN_HEIGHT - 1;
		r = 1;
	}
	if (array[i] -> center.y >= SCREEN_HEIGHT)
	{
		array[i] -> center.y = 1;
		r = 1;
	}
	if (array[i] -> center.x >= SCREEN_WIDTH)
	{
		array[i] -> center.x = 1;
		r = 1;
	}
	if (array[i] -> center.x <= 0)
	{
		array[i] -> center.x = SCREEN_WIDTH - 1;
		r = 1;
	}
	return (r);
}

void	move(t_boid *boid)
{
	t_point new;
	new.x = boid -> dir.x + boid-> avoidForce.x;
	new.y = boid -> dir.y + boid-> avoidForce.y;
	normalize(&new);

	boid -> center.x += new.x * boid -> speed;
	boid -> center.y += new.y * boid -> speed;
}


void	move_boids(t_flock *f, int size)
{
	int i;

	i = 0;
	while(i < size)
	{

		fillInRange(i, f);

		handle_EOW(f->boids, i);

		collision_avoidance(f->boids[i], f->inRange, i);
		move(f->boids[i]);
		i++;
	}
}
