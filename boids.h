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

typedef struct	s_obstacle
{
	t_point a;
	t_point b;
	t_point c;
	t_point d;
}		t_obstacle;

typedef	struct s_boid
{
	t_point	center;
	t_point	dir;
	int		id;
	float	direction;
	float speed;
}		t_boid;

float intersection(float x0, float y0, int r0, float x1, float y1, int r1, t_boid *boid);
int	generate_boids(t_boid **array, int number);
//void	draw_visual_field(t_boid **boids, int nbr, SDL_Renderer *renderer);
void	draw_boids(SDL_Renderer *renderer, t_boid **boid, int number);
void	move_boids(t_boid **array, int number);
#endif
