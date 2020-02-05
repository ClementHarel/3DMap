/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Cursor Behavior
*/

#include "my.h"

void	move_cursor(window_t* win)
{
	sfVector2f	position = set_position(win);

	sfSprite_setPosition(win->cursor, position);
}
