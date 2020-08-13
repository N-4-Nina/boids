#include "boids.h"

int	generate_boids(t_boid **array, int number)
{
	int i;
	//float	direction;
	//t_boid	**array;

	i = 0;
	while (i < number)
	{
		array[i] = malloc(sizeof(t_boid));
		array[i] -> id = i;
		array[i] -> center.x = rand() % SCREEN_WIDTH+1;
		array[i] -> center.y = rand() % SCREEN_HEIGHT+1;

		
		array[i] -> dir.x = (float)rand() / RAND_MAX;
		array[i] -> dir.y = (float)rand() / RAND_MAX;

		if (rand() % 2)
			array[i] -> dir.x = array[i] -> dir.x * -1;
		if (rand() % 2)
			array[i] -> dir.y = array[i] -> dir.y * -1;


		array[i] -> avoidForce.x = 0;
		array[i] -> avoidForce.y = 0;

		array[i] -> speed = 0.75;

		array[i] -> direction = atan2(array[i] -> dir.y, array[i] -> dir.x);

		printf("%f %f \n", array[i] -> dir.x, array[i] -> dir.y);
		//printf("direction = %f\n", array[i] -> direction);

		i++;
	}
	return (0);
}
