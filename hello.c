#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

int
main(int argc, char* argv[])
{
	if (!al_init())
	{
		printf("error initializing allegro\n");
		return EXIT_FAILURE;
	}

	if (!al_install_keyboard())
	{
		printf("error initializing keyboard\n");
		return EXIT_FAILURE;
	}

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
	if (!timer)
	{
		printf("error initializing timer\n");
		return EXIT_FAILURE;
	}

	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	if (!queue)
	{
		printf("error initializing queue\n");
		return EXIT_FAILURE;
	}

	ALLEGRO_DISPLAY* display = al_create_display(640, 480);
	if (!display)
	{
		printf("error initializing display\n");
		return EXIT_FAILURE;
	}

	ALLEGRO_FONT* font = al_create_builtin_font();
	if (!font)
	{
		printf("error initializing font\n");
		return EXIT_FAILURE;
	}

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	bool done = false;
	bool redraw = true;
	ALLEGRO_EVENT event;

	al_start_timer(timer);
	while(1)
	{
		al_wait_for_event(queue, &event);

		switch (event.type)
		{
			case ALLEGRO_EVENT_TIMER:
				// game logic here
				redraw = true;
				break;

			case ALLEGRO_KEY_DOWN:
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				done = true;
				break;

			default:
				// PASS:
				break;
		}

		if (done)
		{
			break;
		}

		if (redraw && al_is_event_queue_empty(queue))
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello!");
			al_flip_display();

			redraw = true;
		}
	}

	al_destroy_font(font);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);

	return EXIT_SUCCESS;
}

