#ifndef BOIDS_H
#define BOIDS_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SEE_AHEAD 2

typedef	struct	s_point
{
	float	x;
	float	y;
}	t_point;

typedef	struct s_boid
{
	int		id;

	t_point	center;
	t_point	dir;
	t_point avoidForce;

	//struct s_boid *avoiding;

	float	direction;
	float speed;
}		t_boid;

void normalize(t_point *vector);

int	generate_boids(t_boid **array, int number);
//void	draw_visual_field(t_boid **boids, int nbr, SDL_Renderer *renderer);
void	collision_avoidance(t_boid **array, int number, int index);
void	draw_boids(SDL_Renderer *renderer, t_boid **boid, int number);
void	move_boids(t_boid **array, int number);
#endif
