/*
** EPITECH PROJECT, 2018
** My world
** File description:
** Window
*/

#include "my.h"

void	poll_event(window_t* win, map_t* map)
{

	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if ((win->event.type == sfEvtKeyReleased && win->event.key.code == 36)
				|| (win->event.type == sfEvtClosed)) {
			sfRenderWindow_close(win->window);
		}
		if ((win->event.type == sfEvtMouseButtonPressed && map->map_x != 0
				&& map->map_y != 0))
			change_coordinate(map, win);
		if ((win->event.type == sfEvtKeyReleased && win->event.key.code == 2))
			map->flag = 0;
		if ((win->event.type == sfEvtKeyReleased && win->event.key.code == 18))
			map->flag = 1;
		else if (win->event.type == sfEvtMouseButtonReleased) {
			check_button_click(win, map);
		}
		if (win->event.type == sfEvtKeyReleased)
			change_x_axis(win, map);
	}
}

void	window_loop(window_t* win, map_t* map)
{
	sfRenderWindow_clear(win->window, sfBlack);
	poll_event(win, map);
	move_cursor(win);
	update_shape(map, win);
	update_map(map, win);
	if (map->flag == 0)
		sfSprite_setTexture(map->mode, win->corner, sfTrue);
	else
		sfSprite_setTexture(map->mode, win->square, sfTrue);
	if (map->text_flag == 0)
		sfSprite_setTexture(map->texture, win->enable, sfTrue);
	else
		sfSprite_setTexture(map->texture, win->disable, sfTrue);
	sfRenderWindow_drawSprite(win->window, map->mode, NULL);
	sfRenderWindow_drawSprite(win->window, map->texture, NULL);
	sfRenderWindow_drawSprite(win->window, map->move, NULL);
	sfRenderWindow_drawSprite(win->window, map->title, NULL);
	sfRenderWindow_drawSprite(win->window, map->quit, NULL);
	sfRenderWindow_drawSprite(win->window, win->cursor, NULL);
	sfRenderWindow_display(win->window);
}

void	title_sprite(map_t* map, window_t* win)
{
	sfTexture*	text = sfTexture_createFromFile("ressources/myworld.png",
		NULL);
	sfVector2f	position = {450, 0};
	sfVector2f	position2 = {44, 210};
	sfVector2f	position3 = {1080, 210};
	sfVector2f	position4 = {44, 600};
	sfVector2f	position5 = {1080, 600};

	win->square = sfTexture_createFromFile("ressources/square.png", NULL);
	win->corner = sfTexture_createFromFile("ressources/corner.png", NULL);
	win->enable = sfTexture_createFromFile("ressources/enable.png", NULL);
	win->disable = sfTexture_createFromFile("ressources/disable.png", NULL);
	win->move = sfTexture_createFromFile("ressources/move.png", NULL);
	win->quit = sfTexture_createFromFile("ressources/quit.png", NULL);
	map->title = sfSprite_create();
	map->mode = sfSprite_create();
	map->texture = sfSprite_create();
	map->move = sfSprite_create();
	map->quit = sfSprite_create();
	sfSprite_setTexture(map->title, text, sfTrue);
	sfSprite_setTexture(map->texture, win->enable, sfTrue);
	sfSprite_setTexture(map->quit, win->quit, sfTrue);
	sfSprite_setTexture(map->move, win->move, sfTrue);
	sfSprite_setPosition(map->title, position);
	sfSprite_setPosition(map->mode, position2);
	sfSprite_setPosition(map->texture, position3);
	sfSprite_setPosition(map->move, position4);
	sfSprite_setPosition(map->quit, position5);
}

void	create_window(window_t* win, map_t* map)
{
	sfTexture* cursor_t = sfTexture_createFromFile("ressources/cursor.png",
	NULL);
	sfClock*	gametime = sfClock_create();
	sfTime		time;

	map->ystep = 0;
	map->xstep = 0;
	win->mode.width = 1400;
	win->mode.height = 800;
	win->mode.bitsPerPixel = 32;
	map->text_flag = 0;
	map->map_x = 9;
	map->map_y = 9;
	win->window = sfRenderWindow_create(win->mode, "My World", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(win->window, 30);
	sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
	win->cursor = sfSprite_create();
	sfSprite_setTexture(win->cursor, cursor_t, sfTrue);
	map->flag = 0;
	title_sprite(map, win);
	while (choose_map(win, map) != 0 && sfRenderWindow_isOpen(win->window));
	if (map->map_x == 0 || map->map_y == 0) {
		map->map_x = 0;
		map->map_y = 0;
	}
	if (map->map_x != 0 && map->map_y != 0) {
		create_coordinate(map);
		create_shape(map);
	}
	while (sfRenderWindow_isOpen(win->window)) {
		time = sfClock_getElapsedTime(gametime);
		if (time.microseconds > 1000) {
			window_loop(win, map);
			sfClock_restart(gametime);
		}
	}
}
