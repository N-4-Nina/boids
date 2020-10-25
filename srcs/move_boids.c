#include "../boids.h"

int isInFOV(t_boid *current, t_boid *considered)
{
	if(two_dis(current->center, considered->center) > 50)
		return (0);

	t_point blindCenter;
	t_point centerToCenter;
	float	dotProd;

	centerToCenter.x = considered->center.x - current->center.x;
	centerToCenter.y = considered->center.y - current->center.y;

	blindCenter.x = -current->dir.x;
	blindCenter.y = -current->dir.y;

	dotProd = centerToCenter.x * blindCenter.x + centerToCenter.y * blindCenter.y;
	if (acos(dotProd) < 0.523599)
		return (0);
	else
		return (1);
}

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
		if (i != index && isInFOV(f->boids[index], f->boids[i]))
		{
			// WOULD BE BETTER WITH AN ANGLE OF VISION RATHER THAN JUST A RADIUS

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
	boid -> center.x += boid -> dir.x * boid -> speed;
	boid -> center.y += boid -> dir.y * boid -> speed;
}


void	move_boids(t_flock *f)
{
	int i;

	i = 0;
	while(i < f->size)
	{
		if (i == 0)
			printf("%f, %f\n",f->boids[i] -> dir.x, f->boids[i]->dir.y);

		fillInRange(i, f);
		handle_EOW(f->boids, i);

		separation(f->boids[i], f->inRange);
		alignment(f->boids[i], f->inRange);
		cohesion(f->boids[i], f->inRange);

		normalize(&f->boids[i] -> dir);
		f->boids[i] -> direction = atan2(f->boids[i] -> dir.y, f->boids[i] -> dir.x);

		move(f->boids[i]);
		i++;
	}
}
