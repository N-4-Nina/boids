#include "boids.h"

int	handle_EOW(t_boid **array, int i)
{
	int	r;

	r = 0;
	if (array[i] -> head.y <= 0)
	{
		array[i] -> head.y = 479;
		r = 1;
	}
	if (array[i] -> head.y >= 480)
	{
		array[i] -> head.y = 1;
		r = 1;
	}
	if (array[i] -> head.x >= 640)
	{
		array[i] -> head.x = 1;
		r = 1;
	}
	if (array[i] -> head.x <= 0)
	{
		array[i] -> head.x = 639;
		r = 1;
	}
	return (r);
}

void	handle_dir(t_boid *boid)
{
	float x;
	float y;
	float rad;


	x = boid -> head.x;
	y = boid -> head.y;
	rad = boid -> direction * 0.0174533;

	boid -> head.x  = x + cos(rad) * 1;
	boid -> head.y = y + sin(rad) * 1;

}

void	update_direction(t_boid *boid, int minus)
{

	boid -> direction += 1 * minus;

	if (boid -> direction >= 360)
		boid -> direction = 0;
	if (boid -> direction <= -1)
		boid -> direction = 359;
}

void	move_boids(t_boid **array, int number)
{
	int i;
	static int minus = 1;

	i = 0;
	while(i < number)
	{
		if (!(rand() % 25))
			minus = -minus;
		if ((rand() % 25))
			update_direction(array[i], minus);
		handle_EOW(array, i);
		handle_dir(array[i]);
		i++;
	}
}
