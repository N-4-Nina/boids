#include "boids.h"

int	generate_boids(t_boid **array, int number)
{
	int i;
	float	direction;
	//t_boid	**array;

	i = 0;
	while (i < number)
	{
		array[i] = malloc(sizeof(t_boid));
		array[i] -> head.x = rand() % 640;
		array[i] -> head.y = rand() % 480;
		array[i] -> direction = rand() % 360;
		direction = array[i] -> direction;
		i++;
	}
	return (0);
}
