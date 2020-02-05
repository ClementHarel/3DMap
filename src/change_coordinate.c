/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Change coordinate
*/

#include "my.h"

void	change_x_axis(window_t* win, map_t* map)
{
	int	i = 0;

	if (win->event.key.code == 71) {
		while (i < (map->map_x * (map->map_y + 1) + map->map_y + 1) + 1) {
			map->coordinate[i].x -= 25;
			i++;
		}
	}
	if (win->event.key.code == 72) {
		while (i < (map->map_x * (map->map_y + 1) + map->map_y + 1) + 1) {
			map->coordinate[i].x += 25;
			i++;
		}
	}
	if (win->event.key.code == 73) {
		while (i < (map->map_x * (map->map_y + 1) + map->map_y + 1) + 1) {
			map->coordinate[i].y += 25;
			i++;
		}
	}
	if (win->event.key.code == 74) {
		while (i < (map->map_x * (map->map_y + 1) + map->map_y + 1) + 1) {
			map->coordinate[i].y -= 25;
			i++;
		}
	}
}
int	get_point(map_t* map, window_t* win)
{
	sfVector2f	window_position = {0, 0};
	sfVector2f	position = {0, 0};
	sfVector3f	coordinate = {0, 0, 0};
	int	i = 1;

	window_position.x = sfRenderWindow_getPosition(win->window).x;
	window_position.y = sfRenderWindow_getPosition(win->window).y;
	position.y = sfMouse_getPosition(win->window_).y
		- window_position.y - CURSOR_Y / 2;
	position.x = sfMouse_getPosition(win->window_).x
		- window_position.x - CURSOR_X / 2;
	position.x += 29;
	position.y += 23;
	while (i < (map->map_x * (map->map_y + 1) + map->map_y + 1) + 1) {
	coordinate.x = cos(0.785398) * (map->coordinate[i].x) - cos(0.785398) *
			(map->coordinate[i].y) + 700;
	coordinate.y = sin(0.610865) * (map->coordinate[i].y) + sin(0.610865) *
			(map->coordinate[i].x) - (map->coordinate[i].z) + 150;
		if (position.x > coordinate.x - 20 && position.x <
				coordinate.x + 20 && position.y  > coordinate.y - 20
				&& position.y < coordinate.y + 20) {
			return (i);
			}
		i++;
	}
	return (-1);
}

void	get_square_next(map_t* map, int corner)
{
	if (corner % (map->map_x + 1) == 0)
		corner--;
	if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
		map->coordinate[corner].z += 10;
		map->coordinate[corner + 1].z += 10;
		map->coordinate[corner - map->map_x].z += 10;
		map->coordinate[corner - map->map_x - 1].z += 10;
	}
	else if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue) {
		map->coordinate[corner].z -= 10;
		map->coordinate[corner + 1].z -= 10;
		map->coordinate[corner - map->map_x].z -= 10;
		map->coordinate[corner - map->map_x - 1].z -= 10;
	}
}

void	get_square(map_t* map, window_t* win)
{
	sfVector2f	window_position = {0, 0};
	sfVector2f	position = {0, 0};
	sfVector3f	coordinate = {0, 0, 0};
	int	i = 1;

	window_position.x = sfRenderWindow_getPosition(win->window).x;
	window_position.y = sfRenderWindow_getPosition(win->window).y;
	position.y = sfMouse_getPosition(win->window_).y
		- window_position.y - CURSOR_Y / 2;
	position.x = sfMouse_getPosition(win->window_).x
		- window_position.x - CURSOR_X / 2;
	position.x += 29;
	position.y += 23;
	while (i < (map->map_x * (map->map_y + 1) + map->map_y + 1) + 1) {
	coordinate.x = cos(0.785398) * (map->coordinate[i].x) - cos(0.785398) *
			(map->coordinate[i].y) + 700;
	coordinate.y = sin(0.610865) * (map->coordinate[i].y) + sin(0.610865) *
			(map->coordinate[i].x) - (map->coordinate[i].z) + 150;
		if (position.x > coordinate.x - 50 &&
				position.x < coordinate.x + 50
				&& position.y > coordinate.y - 50 &&
				position.y < coordinate.y + 50) {
			get_square_next(map, i + map->map_x + 1);
			return;
	}
		i++;
	}
}

void	change_coordinate(map_t* map, window_t* win)
{
	int point = get_point(map, win);

	if (map->flag == 0)
		point = get_point(map, win);
	else {
		get_square(map, win);
		return;
	}
	if (point == -1)
		return;
	if  (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
		map->coordinate[point].z += 10;
	else if  (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
		map->coordinate[point].z -= 10;
}
