#include "boids.h"

int main(int argc, char **argv)
{
	int	end;
	if (argc != 2)
		return(printf("Need number of boids"));


	int nbr = atoi(argv[1]);
	t_flock	flock;
	//flock = malloc(sizeof(t_flock));
	t_boid	*boids[nbr];
	flock.size = nbr;
	flock.boids = boids;
	printf("ok\n");
	generate_boids(&flock);
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

		move_boids(&flock, nbr);

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
