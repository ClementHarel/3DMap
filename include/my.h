/*
** EPITECH PROJECT, 2018
** Bonsoir
** File description:
** Pere
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
//#define MAP_Y 10
//#define MAP_X 10
#define CURSOR_X 80
#define CURSOR_Y 51

typedef struct {
	sfVideoMode		mode;
	sfRenderWindow*		window;
	sfWindow*		window_;
	sfEvent			event;
	sfSprite*		cursor;
	sfTexture*		square;
	sfTexture*		corner;
	sfTexture*		enable;
	sfTexture*		disable;
	sfTexture*		quit;
	sfTexture*		move;
} window_t;

typedef struct {
	sfVector3f*		coordinate;
	int				magic_loop;
	sfVertexArray**		array;
	sfConvexShape**		shape;
	int	      		flag;
	int	       		text_flag;
	sfSprite*		title;
	sfSprite*		mode;
	sfSprite*		texture;
	sfSprite*		move;
	int		       	map_x;
	int			map_y;
	sfSprite*		choose_x;
	sfSprite*		choose_y;
	sfSprite*		empty;
	sfSprite*		ok;
	sfSprite*		quit;
	sfText*			text;
	sfText*			text2;
	sfFont*			font;
	int		       	ystep;
	int	       		xstep;
	char			first;
	char			second;
//	int				cosine;
//	int				sinus;
} map_t;

int	ystep(window_t* win, map_t* map);
int	choose_map(window_t* win, map_t* map);
sfVector2f	set_position(window_t* win);sfVector2f	set_position(window_t* win);
void    check_button_click(window_t* win, map_t* map);
void	update_shape(map_t* map, window_t* win);
void	create_shape(map_t* map);
sfVertexArray*	create_line(sfVector3f first_point, sfVector3f second_point, map_t* map);
void	change_x_axis(window_t* win, map_t* map);
void	change_coordinate(map_t* map, window_t* win);
void	create_coordinate(map_t* map);
void	update_map(map_t* map, window_t* win);
void	create_window(window_t* win, map_t* map);
void	move_cursor(window_t* win);
