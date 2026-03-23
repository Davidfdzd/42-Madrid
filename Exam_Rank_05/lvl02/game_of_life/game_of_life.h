#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct
{
	int width;
	int height;
	int x;
	int y;
	int drawing;
	char	**grid;
} Board;

Board	*create_board(int w, int h);
void	free_board(Board *b);
void	process_input(Board *b);
void	simulate(Board *b);
void	print_board(Board *b);

#endif
