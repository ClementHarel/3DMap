/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Check if button is pressed
*/

#include "my.h"

void	reset(map_t* map)
{
	int i = 0;

	while (i < (map->map_x * (map->map_y + 1) + map->map_y + 1) + 1) {
		map->coordinate[i].z = 0;
		i++;
	}
}

sfVector2f	set_position(window_t* win)
{
	sfVector2f	position;
	sfVector2f	window_position;

	window_position.x = sfRenderWindow_getPosition(win->window).x;
	window_position.y = sfRenderWindow_getPosition(win->window).y;
	position.y = sfMouse_getPosition(win->window_).y
		- window_position.y - CURSOR_X / 2;
	position.x = sfMouse_getPosition(win->window_).x
		- window_position.x - CURSOR_Y / 2;
	return (position);
}

void	check_button_click(window_t* win, map_t* map)
{
	sfVector2f position = set_position(win);

	if (position.y >= 218 && position.y <= 342 && position.x >= 1092
			&& position.x <= 1372) {
		if (map->text_flag == 0) {
			map->text_flag = 1;
			return;
		} else {
			map->text_flag = 0;
			return;
		}
	}
	if (position.y >= 600 && position.y <= 736 && position.x >= 1088
			&& position.x <= 1367 && map->map_x != 0 && map->map_y != 0) {
		reset(map);
		return;
	}
}
