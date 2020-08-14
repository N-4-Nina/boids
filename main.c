#include "boids.h"

int main(int argc, char **argv)
{
	int	end;
	int seed;
	seed = -1;
	if (argc < 2)
		return(printf("Need number of boids"));
	if (argc > 4)
		return(printf("Too much arguments. First is number of boids, second is seed (optional)."));
	if (argc == 3)
	{
		seed = atoi(argv[2]);
		if (seed < 0)
			return(printf("Seed must be positive."));
	}

	int nbr = atoi(argv[1]);
	t_flock	flock;
	t_boid	*boids[nbr];
	flock.size = nbr;
	flock.boids = boids;
	printf("ok\n");
	generate_boids(&flock, seed);
	printf("ok\n");

	SDL_Window *mainWindow;                    // Declare a pointer
	SDL_Renderer *renderer;
	SDL_Init(SDL_INIT_VIDEO);


	SDL_Event evenements = {0};
	end = 0;
	mainWindow = SDL_CreateWindow(
			"boids",                  // window title
			SDL_WINDOWPOS_UNDEFINED,           // initial x position
			SDL_WINDOWPOS_UNDEFINED,           // initial y position
			SCREEN_WIDTH,                        // width, in pixels
			SCREEN_HEIGHT,                      // height, in pixels
			SDL_WINDOW_OPENGL                  // flags - see below
			);
	if (mainWindow == NULL)
	{
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
	while(!end)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		draw_boids(renderer, flock.boids, nbr);

		move_boids(&flock);

		SDL_RenderPresent(renderer);
		SDL_WaitEventTimeout(&evenements, 0);


		if(evenements.type == SDL_QUIT)
			end = 1;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	}

	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
	return EXIT_SUCCESS;
}
