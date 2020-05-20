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
	float x;
	float y;
	float cx, cy;
	float rad;


	x = boid -> center.x;
	y = boid -> center.y;

	rad = boid -> direction;

	boid -> center.x  += boid -> dir.x*0.25;
	boid -> center.y += boid -> dir.y*0.25;
}

void	update_direction(t_boid **array, int number, int index)
{
	int i;
	int check;
	float dist;
	float newdist;

	i = 0;
	dist = -1;
	while(i < number)
	{
		if (array[i] -> id != array[index] -> id)
		{
			newdist = sqrt(pow(array[i] -> center.y - array[index] -> center.y, 2) + pow(array[i] -> center.x - array[index] -> center.x, 2));
			if ((dist == -1 || dist > newdist) && newdist < 70)
			{
				check = i;
				intersection(array[check] -> center.x, array[check] -> center.y, 35, array[index] -> center.x, array[index] -> center.y, 40, array[index]);
				dist = newdist;
			}
		}
		i++;
	}
	//intersection(array[check] -> center.x, array[check] -> center.y, 35, array[index] -> center.x, array[index] -> center.y, 40, array[index]);
	handle_dir(array[index]);
}

void	move_boids(t_boid **array, int number)
{
	int i;

	i = 0;
	while(i < number)
	{

		update_direction(array, number, i);
		handle_EOW(array, i);
		//handle_dir(array[i]);
		i++;
	}
}
