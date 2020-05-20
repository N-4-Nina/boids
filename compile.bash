gcc -D SCREEN_WIDTH=840 -D SCREEN_HEIGHT=850 main.c  generate_boids.c move_boids.c draw_boids.c intersection.c -I include boids.h -l SDL2-2.0.0 && ./a.out 25
