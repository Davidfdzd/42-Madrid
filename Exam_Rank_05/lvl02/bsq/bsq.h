#ifndef BSQ_H
# define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct
{
	int rows;
	int cols;
	char empty;
	char obstacle;
	char full;
	char **grid;
} Map;

Map	*load_map(const char *filename);
Map	*load_map_stdin(void);
int	validate_map(Map *map);
void	print_map(Map *map);
void	solve_map(Map *map);
void	free_map(Map *map);

#endif
