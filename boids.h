#ifndef BOIDS_H
#define BOIDS_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef	struct	s_point
{
	float	x;
	float	y;
}	t_point;

typedef	struct s_boid
{
	t_point	head;
	t_point	l;
	t_point	r;
	float	direction;

}		t_boid;
/*
typedef	struct	s_point
{
	int	x;
	int	y;
}		t_point;
*/
int	generate_boids(t_boid **array, int number);
void	draw_boids(SDL_Renderer *renderer, t_boid **boid, int number);
void	move_boids(t_boid **array, int number);
#endif
