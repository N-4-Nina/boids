#include "boids.h"

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

void	handle_dir(t_boid *boid)
{
	t_point new;
	new.x = boid -> dir.x + boid-> avoidForce.x;
	new.y = boid -> dir.y + boid-> avoidForce.y;
	normalize(&new);

	boid -> center.x += new.x * boid -> speed;
	boid -> center.y += new.y * boid -> speed;
}


void	move_boids(t_boid **array, int number)
{
	int i;

	i = 0;
	while(i < number)
	{

		handle_EOW(array, i);
		collision_avoidance(array, number, i);
		handle_dir(array[i]);
		i++;
	}
}
