#include "boids.h"

int main(int argc, char **argv)
{
	int	end;
	if (argc != 2)
		return(printf("Need number of boids"));


	int nbr = atoi(argv[1]);
	t_boid	*array[nbr];
	printf("ok\n");
	generate_boids(array, nbr);
	printf("ok\n");


	SDL_Window *window;                    // Declare a pointer
	SDL_Renderer *renderer;
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Event evenements = {0};
	end = 0;
	window = SDL_CreateWindow(
			"boids",                  // window title
			SDL_WINDOWPOS_UNDEFINED,           // initial x position
			SDL_WINDOWPOS_UNDEFINED,           // initial y position
			640,                               // width, in pixels
			480,                               // height, in pixels
			SDL_WINDOW_OPENGL                  // flags - see below
			);
	if (window == NULL) {
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	while(!end)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		draw_boids(renderer, array, nbr);
		move_boids(array, nbr);
		SDL_RenderPresent(renderer);
		SDL_WaitEventTimeout(&evenements, 0);
		                         

		if(evenements.type == SDL_QUIT)
			end = 1;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}