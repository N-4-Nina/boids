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

	int		inRange;

	t_point	center;
	t_point	dir;
	t_point avoidForce;

	//struct s_boid *avoiding;
	float	direction;
	float speed;
}		t_boid;

typedef	struct s_flock
{
	int size;

	t_boid	**boids;
	t_boid	**inRange;

}	t_flock;

float two_dis(t_point firstPoint, t_point secondPoint);
void normalize(t_point *vector);

int	generate_boids(t_flock *f);
//void	draw_visual_field(t_boid **boids, int nbr, SDL_Renderer *renderer);
void	collision_avoidance(t_boid *looking, t_boid **array, int index);
void	draw_boids(SDL_Renderer *renderer, t_boid **boid, int number);
void	move_boids(t_flock *f, int number);
#endif
