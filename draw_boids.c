#include "boids.h"

void	draw_boids(SDL_Renderer *renderer, t_boid **boid, int number)
{
	int i;
	float	hx;
	float	hy;
	float	lx;
	float	ly;
	float	rx;
	float	ry;
	float cx;
	float cy;
	float dist;

	int	dir;
	i = 0;
	while (i < number)
	{

		hx = boid[i] -> center.x + cos(boid[i] -> direction)*10;
		hy = boid[i] -> center.y + sin(boid[i] -> direction)*10;
		//printf("boid %i, %f, %f,\n", i, hx, hy);
		lx = boid[i] -> center.x - cos(boid[i] -> direction + 0.523599)*10;
		ly = boid[i] -> center.y - sin(boid[i] -> direction + 0.523599)*10;

		rx = boid[i] -> center.x - cos(boid[i] -> direction - 0.523599)*10;
		ry = boid[i] -> center.y - sin(boid[i] -> direction - 0.523599)*10;


		dir = boid[i] -> direction;

		dist = round(sqrt(pow(hx - boid[i] -> center.x, 2) + pow(hy - boid[i] -> center.y, 2)));

		SDL_RenderDrawLine(renderer, hx, hy, lx, ly);
		SDL_RenderDrawLine(renderer, hx, hy, rx, ry);

		SDL_RenderDrawLine(renderer, lx, ly, boid[i] -> center.x, boid[i] -> center.y);
		SDL_RenderDrawLine(renderer, rx, ry, boid[i] -> center.x, boid[i] -> center.y);


		i++;
	}

}
