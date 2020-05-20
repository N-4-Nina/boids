#include "boids.h"



float intersection(float x0, float y0, int r0, float x1, float y1, int r1, t_boid *boid)
{
        float a, dx, dy, dx1, dy1, dx2, dy2, d, dprime, dprime2, h, rx, ry;
        float x2, y2;
        float dircopy1 = boid -> direction + 0.0174533;
        float dircopy2 = boid -> direction - 0.0174533;
        t_point new1, new2;
        /* dx and dy are the vertical and horizontal distances between
         * the circle centers.
         */
        dx = x1 - x0;
        dy = y1 - y0;

        /* Determine the straight-line distance between the centers. */
        d = sqrt((dy*dy) + (dx*dx));

        /* Check for solvability. */
        if (d > (r0 + r1)) {
            /* no solution. circles do not intersect. */
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

    /* 'point 2' is the point where the line through the circle
     * intersection points crosses the line between the circle
     * centers.



    /* Determine the distance from point 0 to point 2.
    a = ((r0*r0) - (r1*r1) + (d*d)) / (2.0 * d) ;

    /* Determine the coordinates of point 2.
    x2 = x0 + (dx * a/d);
    y2 = y0 + (dy * a/d);

    /* Determine the distance from point 2 to either of the
     * intersection points.

    h = sqrt((r0*r0) - (a*a));

    /* Now determine the offsets of the intersection points from
     * point 2.

    rx = -dy * (h/d);
    ry = dx * (h/d);

    /* Determine the absolute intersection points.
    float xi = x2 + rx;
    float xi_prime = x2 - rx;
    float yi = y2 + ry;
    float yi_prime = y2 - ry;
    //float ret[4] = [floor(xi), floor(xi_prime), floor(yi), floor(yi_prime)];
    */
