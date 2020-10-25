#include "../boids.h"



float intersection(float x0, float y0, int r0, float x1, float y1, int r1, t_boid *boid)
{
        float dx, dy, dx1, dy1, dx2, dy2, d, dprime, dprime2;
        float dircopy1 = boid -> direction + 0.0174533;
        float dircopy2 = boid -> direction - 0.0174533;
        t_point new1, new2;
        /*
         * dx and dy are the vertical and horizontal distances between
         * the circle centers.
         */
        dx = x1 - x0;
        dy = y1 - y0;

        /*
        Determine the straight-line distance between the centers.
        */
        d = sqrt((dy*dy) + (dx*dx));

        /*
        Check for solvability.
        */
        if (d > (r0 + r1)) {
            /*
            no solution. circles do not intersect.
            */
            return 0;
        }


        new1.x = cos(dircopy1);
        new1.y = sin(dircopy1);
        dx1 = new1.x - x0;
        dy1 = new1.y - y0;
        dprime = sqrt((dy1*dy1) + (dx1*dx1));

        new2.x = cos(dircopy2);
        new2.y = sin(dircopy2);
        dx2 = new2.x - x0;
        dy2 = new2.y - y0;
        dprime2 = sqrt((dy2*dy2) + (dx2*dx2));

        boid -> dir.x = (rand() % 2) ? new1.x : new2.x;
        boid -> dir.y = (rand() % 2) ? new1.y : new2.y;

        //boid -> dir.y = sin(boid -> direction);
        boid -> direction = atan2(boid->dir.y, boid->dir.x);
        if (dprime == dprime2 && boid->id)
        {
          printf("BOLOSSE dirx= %f, diry=%f \n", boid -> dir.x, boid -> dir.y);
        }
        return(1);
    }
