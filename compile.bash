gcc -D SCREEN_WIDTH=1440 -D SCREEN_HEIGHT=900 main.c  utils.c collision_avoidance.c generate_boids.c move_boids.c draw_boids.c -I include boids.h -l SDL2-2.0.0 && ./a.out 25
