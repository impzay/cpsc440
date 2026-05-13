//For this lab, I decided to pick a moon jellyfish to draw with my primitives, I used some simple filled ellipses for the body
//For the tentacles, I made a simple for loop that will draw 10 tentacles, using the spline function, I had to use an array of points that get modify the x_start variable every step of the loop. 

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(int argc, char** argv) {
	ALLEGRO_DISPLAY* display = NULL;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	display = al_create_display(1920, 1080);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	
	//tentacles
	for (int i = 0; i < 10; i++) {
			float x_start = 775 + (i * 50);
			float y_start = 325;
			float points[8] = {
				x_start, y_start,
				x_start - 50, y_start + 150,
				x_start + 50, y_start + 310,
				x_start, y_start + 500
			};

			al_draw_spline(points, al_map_rgb(200, 150, 200), 5.0);
		};

	//body of jellyfish
	al_draw_filled_ellipse(1000, 300, 300, 100, al_map_rgb(0, 100, 255));
	al_draw_filled_ellipse(1150, 300, 75, 25, al_map_rgb(255, 255, 255));
	al_draw_filled_ellipse(850, 300, 75, 25, al_map_rgb(255, 255, 255));
	al_draw_filled_ellipse(1000, 240, 20, 35, al_map_rgb(255, 255, 255));
	al_draw_filled_ellipse(1000, 340, 20, 35, al_map_rgb(255, 255, 255));

	//bubbles
	al_draw_circle(1450, 200, 10, al_map_rgb(255, 255, 255), 3);
	al_draw_circle(1500, 150, 10, al_map_rgb(255, 255, 255), 3);
	al_draw_circle(1450, 100, 10, al_map_rgb(255, 255, 255), 3);
	al_draw_circle(1500, 50, 10, al_map_rgb(255, 255, 255), 3);



	al_flip_display();
	al_rest(3.0);
	al_destroy_display(display);
	return 0;
}