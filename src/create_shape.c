/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Create shape for textures
*/

#include "my.h"

sfVector2f	iso(sfVector3f point)
{
	sfVector2f	new;

	new.x = cos(0.785398) * (point.x) - cos(0.785398) * (point.y);
	new.y = sin(0.610865) * (point.y) + sin(0.610865) * (point.x) - point.z;
	new.x += 700;
	new.y += 150;
	return(new);
}

void	update_shape(map_t* map, window_t* win)
{
	int i = 1;
	int sahakian = 0;
	sfVector2f position = {0, 0};

	if (map->text_flag == 0)
		return;
	while (i < map->map_x * map->map_y + map->map_y) {
		sfConvexShape_setPointCount(map->shape[i - 1], 4);
		position = iso(map->coordinate[i]);
		sfConvexShape_setPoint(map->shape[i - 1], 0, position);
		position = iso(map->coordinate[i + map->map_x + 1]);
		sfConvexShape_setPoint(map->shape[i - 1], 1, position);
		position = iso(map->coordinate[i + map->map_x + 2]);
		sfConvexShape_setPoint(map->shape[i - 1], 2, position);
		position = iso(map->coordinate[i + 1]);
		sfConvexShape_setPoint(map->shape[i - 1], 3, position);

		i++;
	}
	i = 0;
	while (i <  map->map_x * map->map_y + map->map_y) {
		if (sahakian != map->map_x) {
       			sfRenderWindow_drawConvexShape(win->window, map->shape[i], NULL);
       			sahakian += 1;
		}
		else
			sahakian = 0;
		i++;
	}
}


void	create_shape(map_t* map)
{
	int i = 0;
	sfTexture* grass = sfTexture_createFromFile("ressources/grass.png",
	NULL);
	map->shape = malloc(2048);
	while (i < map->map_x * map->map_y + map->map_y) {
		map->shape[i] = sfConvexShape_create();
		sfConvexShape_setTexture(map->shape[i], grass, sfTrue);
		i++;
	}
}
