/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Choose map X & Y
*/

#include "my.h"

void	check_buttony(window_t* win, map_t* map)
{
	sfVector2f position = set_position(win);

	if (position.y >= 630 && position.y <= 706 && position.x >= 608
			&& position.x <= 889) {
		map->map_y = (map->second - '0');
		map->ystep = 1;
	}
	if (position.y >= 400 && position.y <= 540 && position.x >= 610
			&& position.x <= 890) {
			if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
				map->second++;
			else if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
				map->second--;
			if (map->second == '0' - 1)
				map->second = '9';
			else if (map->second == '9' + 1)
				map->second = '0';
	}
}

int	poll_event_choosey(window_t* win, map_t* map)
{
	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if ((win->event.type == sfEvtKeyPressed && win->event.key.code == 36)
				|| (win->event.type == sfEvtClosed)) {
			sfRenderWindow_close(win->window);
			return (1);
		}
        if (win->event.type == sfEvtMouseButtonPressed)
		check_buttony(win, map);
	}
	return (0);
}

void	first_sety(map_t* map)
{
	sfTexture* choose_x = sfTexture_createFromFile("ressources/height.png",
	NULL);
	sfTexture* empty = sfTexture_createFromFile("ressources/empty.png",
	NULL);
	sfTexture* ok = sfTexture_createFromFile("ressources/ok.png",
	NULL);
	sfVector2f	position = {410, 200};
	sfVector2f	position2 = {600, 400};
	sfVector2f	position3 = {600, 625};
	sfColor color = {0, 0, 0, 255};

    map->font = sfFont_createFromFile("ressources/moon_get-Heavy.ttf");
    map->text = sfText_create();
    map->text2 = sfText_create();
    sfText_setFont(map->text, map->font);
    sfText_setFont(map->text2, map->font);
	map->empty = sfSprite_create();
    sfText_setCharacterSize(map->text, 45);
    sfText_setCharacterSize(map->text2, 45);
    sfText_setColor(map->text, color);
    sfText_setColor(map->text2, color);
	sfSprite_setPosition(map->empty, position2);
    position2.x += 75;
    position2.y += 40;
    sfText_setPosition(map->text, position2);
    position2.x += 40;
    sfText_setPosition(map->text2, position2);
	map->choose_x = sfSprite_create();
	map->choose_y = sfSprite_create();
	map->ok = sfSprite_create();
	sfSprite_setTexture(map->choose_x, choose_x, sfTrue);
	sfSprite_setTexture(map->empty, empty, sfTrue);
	sfSprite_setTexture(map->ok, ok, sfTrue);
	sfSprite_setPosition(map->choose_x, position);
	sfSprite_setPosition(map->ok, position3);
}

void	check_lenghty(map_t* map)
{
	map->first = '0';
	map->second = '0';
}

int	ystep(window_t* win, map_t* map)
{
	static int first = 0;
	char string[2];

	sfRenderWindow_clear(win->window, sfBlack);
	if (first == 0) {
		first_sety(map);
		check_lenghty(map);
		first = 1;
	}
	move_cursor(win);
	if (poll_event_choosey(win, map) == 1)
		return (0);
	string[0] = map->second;
	string[1] = '\0';
	sfText_setString(map->text2, string);
	sfRenderWindow_drawSprite(win->window, map->title, NULL);
	sfRenderWindow_drawSprite(win->window, map->choose_x, NULL);
	sfRenderWindow_drawSprite(win->window, map->empty, NULL);
	sfRenderWindow_drawSprite(win->window, map->ok, NULL);
	sfRenderWindow_drawText(win->window, map->text, NULL);
	sfRenderWindow_drawText(win->window, map->text2, NULL);
	sfRenderWindow_drawSprite(win->window, win->cursor, NULL);
	sfRenderWindow_display(win->window);
	if (map->ystep == 1)
		return (0);
	return (1);
}
