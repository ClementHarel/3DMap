/*
** EPITECH PROJECT, 2018
** My world
** File description:
** Create a line
*/

#include "my.h"

sfVector2f	isometric(sfVector3f point)
{
	sfVector2f	new;

	new.x = cos(0.785398) * (point.x) - cos(0.785398) * (point.y);
	new.y = sin(0.610865) * (point.y) + sin(0.610865) * (point.x) - point.z;
	new.x += 700;
	new.y += 150;
	return (new);
}

sfVertexArray*	create_line(sfVector3f first_point, sfVector3f second_point, map_t* map)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex	vertex_one;
	sfVertex	vertex_two;
	sfVector2f first = isometric(first_point);
	sfVector2f second = isometric(second_point);
	vertex_one.position = first;
	vertex_two.position = second;
	if (map->flag == 0) {
		vertex_one.color = sfBlue;
		vertex_two.color = sfCyan;
	}
	if (map->flag == 1) {
		vertex_one.color = sfRed;
		vertex_two.color = sfMagenta;
	}
	vertex_array = sfVertexArray_create();
	sfVertexArray_append(vertex_array, vertex_one);
	sfVertexArray_append(vertex_array, vertex_two);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

void	create_coordinate(map_t* map)
{
	int	i = 0;
	int	j = 0;
	int	x = 50;
	int	y = 50;
	int	number = 0;

	map->coordinate = malloc(sizeof(sfVector3f) *
			((map->map_x * (map->map_y + 1)) + map->map_y + 1) * 2);
	map->array = malloc(sizeof(sfVertex) * (map->map_y * (map->map_x + 1)) + 1);
	while (j < map->map_y + 1) {
		while (i < map->map_x + 1) {
			number++;
			map->coordinate[number].x = x;
			map->coordinate[number].y = y;
			map->coordinate[number].z = 0;
			x += 64;
			i++;
		}
		i = 0;
		x = 50;
		y += 64;
		j++;
	}
}

void	update_map(map_t* map, window_t* win)
{
	int	i = 1;

	while (i < map->map_x * (map->map_y + 1) + map->map_y + 1) {
		if (i % (map->map_x + 1) != 0) {
			map->array[i] = create_line(map->coordinate[i],
					map->coordinate[i + 1], map);
			sfRenderWindow_drawVertexArray(win->window, map->array[i], NULL);
	}
		i++;
		}
	i = 1;
	while (i < map->map_y * map->map_x + map->map_y + 1) {
			map->array[i] = create_line(map->coordinate[i],
					map->coordinate[i + map->map_x + 1], map);
			sfRenderWindow_drawVertexArray(win->window, map->array[i], NULL);
		i++;
	}
}
