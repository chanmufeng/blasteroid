

#include <math.h>
#include <allegro5/allegro_primitives.h>
#include "asteroid.h"


void asteroids_init(Asteroid a[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        a[i].live = 0;
        a[i].speed = 0.9;
        a[i].rot_velocity = 2;
        
        a[i].color = al_map_rgb(220,220,220);
    }
}

void asteroids_appear(Asteroid a[], int size, int width, int height) {
    int i;
    for (i = 0; i < size; i++) {
        if(!a[i].live) {
            a[i].heading = rand();
            a[i].scale = 3;
            a[i].live = 1;
            a[i].sx = width;
            a[i].sy = 30 + rand() % (height -60) ;
            break;                
        }        
    }

}

void asteroids_move(Asteroid a[], int size, int width, int height) {
    int i;   
    for (i = 0; i < size; i++) {
        if (a[i].live) {
            a[i].sx += a[i].speed * sin(a[i].heading);
            a[i].sy -= a[i].speed * cos(a[i].heading);

            // loop boundary
            if (a[i].sx < 0) 
                a[i].sx += width;
            if (a[i].sx > width) 
                a[i].sx -= width;
            if (a[i].sy < 0)
                a[i].sy += height;
            if (a[i].sy > height)
                a[i].sy -= height;
        }
    }
}

void asteroids_draw(Asteroid a[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (a[i].live) {
            
            ALLEGRO_TRANSFORM transform;
            al_identity_transform(&transform);
            al_rotate_transform(&transform, a[i].heading);
            al_translate_transform(&transform, a[i].sx, a[i].sy);
            al_use_transform(&transform);
            
            al_draw_line(-20,  20, -25,   5, a[i].color, 2.0f);
            al_draw_line(-25,   5, -25, -10, a[i].color, 2.0f);
            al_draw_line(-25, -10,  -5, -10, a[i].color, 2.0f);
            al_draw_line( -5, -10, -10, -20, a[i].color, 2.0f);
            al_draw_line(-10, -20,   5, -20, a[i].color, 2.0f);
            al_draw_line(  5, -20,  20, -10, a[i].color, 2.0f);
            al_draw_line( 20, -10,  20,  -5, a[i].color, 2.0f);
            al_draw_line( 20,  -5,   0,   0, a[i].color, 2.0f);
            al_draw_line(  0,   0,  20,  10, a[i].color, 2.0f);
            al_draw_line( 20,  10,  10,  20, a[i].color, 2.0f);
            al_draw_line( 10,  20,   0,  15, a[i].color, 2.0f);
            al_draw_line(  0,  15, -20,  20, a[i].color, 2.0f);
        }
        
    }

}