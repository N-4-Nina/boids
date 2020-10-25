#include "../boids.h"

int	generate_boids(t_flock *f, int seed)
{
	int i = 0;

	printf("Generating %d boids...\n", f->size);
	f->inRange = malloc(f->size * sizeof(t_boid*));
	f->boids = malloc(f->size * sizeof(t_boid*));

	if (seed != -1)
		srand((unsigned)seed);
	while (i < f->size)
	{
			//printf("generating boid %d out of %d", i, f->size);
			f->inRange[i] = malloc(sizeof(t_boid));
			f->boids[i] = malloc(sizeof(t_boid));
			f->boids[i] -> id = i;
			f->boids[i] -> inRange = 0;
			f->boids[i] -> center.x = rand() % SCREEN_WIDTH+1;
			f->boids[i] -> center.y = rand() % SCREEN_HEIGHT+1;

			f->boids[i] -> dir.x = (float)rand() / RAND_MAX;
			f->boids[i] -> dir.y = (float)rand() / RAND_MAX;

			if (rand() % 2)
				f->boids[i] -> dir.x = f->boids[i] -> dir.x * -1;
			if (rand() % 2)
				f->boids[i] -> dir.y = f->boids[i] -> dir.y * -1;


			f->boids[i] -> avoidForce.x = 0;
			f->boids[i] -> avoidForce.y = 0;

			f->boids[i] -> speed = 1;

			f->boids[i] -> direction = atan2(f->boids[i] -> dir.y, f->boids[i] -> dir.x);

			printf("%f %f \n", f->boids[i] -> dir.x, f->boids[i] -> dir.y);
			//printf("direction = %f\n", f->boids[i] -> direction);

			i++;
	}

	return (0);
}
