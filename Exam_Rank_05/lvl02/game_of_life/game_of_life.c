#include "game_of_life.h"

Board	*create_board(int w, int h)
{
	Board *b = malloc(sizeof(Board));
	if (!b) return NULL;

	b->width = w;
	b->height = h;
	b->x = 0;
	b->y = 0;
	b->drawing = 0;

	b->grid = malloc(h * sizeof(char *));
	if (!b->grid)
	{
		free(b);
		return NULL;
	}

	for (int i = 0; i < h; i++)
	{
		b->grid[i] = malloc(w);
		if (!b->grid[i])
		{
			for (int j = 0; j < i; j++) free(b->grid[j]);
			free(b->grid);
			free(b);
			return NULL;
		}
		for (int j = 0; j < w; j++)
			b->grid[i][j] = ' ';
	}
	return b;
}

void	free_board(Board *b)
{
	if (!b) return;
	for	(int i = 0; i < b->height; i++)
		free(b->grid[i]);
	free(b->grid);
	free(b);
}

void	process_input(Board *b)
{
	char c;
	
	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
		{
			b->drawing = !b->drawing;
			if (b->drawing)
				b->grid[b->y][b->x] = '0';
		}
		else if (c == 'w' && b->y > 0) b->y--;
		else if (c == 's' && b->y < b->height) b->y++;
		else if (c == 'a' && b->x > 0) b->x--;
		else if (c == 'd' && b->x < b->width) b->x++;

		if (b->drawing)
			b->grid[b->y][b->x] = '0';
	}
}

void	print_board(Board *b)
{
	for	(int i = 0; i < b->height; i++)
	{
		for	(int j = 0; j < b->width; j++)
			putchar(b->grid[i][j]);
		putchar('\n');
	}
}

static	int	count_neightbors(Board *b, int y, int x)
{ //cuenta los vecinos vivos
	int count = 0;
	for (int dy = -1; dy <= 1; dy++)
	{
		for (int dx = -1; dx <= 1; dx++) //todas las posibilidades de alredeor de casilla
		{	
			if (dy == 0 && dx == 0) //ignoro mi casilla
				continue;
			
			int ny = y + dy; //calculo la posicion del vecino
			int nx = x + dx;
			if (ny >= 0 && ny < b->height && nx >= 0 && nx < b->width)
				if (b->grid[ny][nx] == '0') //compruebo si esta dentro del tablero
					count++; //si es '0' esta vivo y lo cuento
		}
	}
	return count;
}

void	simulate(Board * b)
{
	char	**new_grid = malloc(b->height * sizeof(char *));
	for (int i = 0; i < b->height; i++)
	{
		new_grid[i] = malloc(b->width);
		for	(int j = 0; j < b->width; j++)
		{
			int neighbors = count_neightbors(b, i, j);
			if (b->grid[i][j] == '0')
			{
				if (neighbors == 2 || neighbors == 3)
					new_grid[i][j] = '0';
				else
					new_grid[i][j] = ' ';
			}
			else
			{
				if (neighbors == 3)
					new_grid[i][j] = '0';
				else
					new_grid[i][j] = ' ';
			}
		}
	}

	for	(int i = 0; i < b->height; i++)
	{
		for	(int j = 0; j < b->width; j++)
			b->grid[i][j] = new_grid[i][j];
		free (new_grid[i]);
	}
	free (new_grid);
}



