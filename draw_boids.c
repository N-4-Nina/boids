#include "boids.h"

void	draw_boids(SDL_Renderer *renderer, t_boid **boid, int number)
{
	int i;
	float	x;
	float	y;
	float	lx;
	float	ly;
	float	rx;
	float	ry;
	float	mx;
	float	my;

	int	dir;
	i = 0;
	while (i < number)
	{
		
		x = boid[i] -> head.x;
		y = boid[i] -> head.y;
		
		lx = boid[i] -> head.x - cos((boid[i] -> direction + 15) * 0.0174533)*20;
		ly = boid[i] -> head.y - sin((boid[i] -> direction + 15) * 0.0174533)*20;

		rx = boid[i] -> head.x - cos((boid[i] -> direction - 15) * 0.0174533)*20;
		ry = boid[i] -> head.y - sin((boid[i] -> direction - 15) * 0.0174533)*20;

		mx = boid[i] -> head.x - cos((boid[i] -> direction) * 0.0174533)*10;
		my = boid[i] -> head.y - sin((boid[i] -> direction) * 0.0174533)*10;
		
		dir = boid[i] -> direction;


		SDL_RenderDrawLine(renderer, x, y, lx, ly);
		SDL_RenderDrawLine(renderer, x, y, rx, ry);

		SDL_RenderDrawLine(renderer, lx, ly, mx, my);
		SDL_RenderDrawLine(renderer, rx, ry, mx, my);


		//SDL_RenderDrawLine(renderer, x, y, rx, ry);


		//SDL_RenderDrawLine(renderer, x, y, x-cos(dir)*-10 , y-sin(dir)*20);
		//SDL_RenderDrawLine(renderer, x, y, x-cos(dir)*10, y-sin(dir)* 20);


		//SDL_RenderDrawLine(renderer, x-10, y+20, x, y+10);
		//SDL_RenderDrawLine(renderer, x+10, y+20, x, y+10);
		

		i++;
	}

}
