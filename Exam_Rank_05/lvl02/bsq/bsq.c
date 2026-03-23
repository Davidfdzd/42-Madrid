#include "bsq.h"

static int	parse_header(FILE *fp, Map *map)
{
	if (fscanf(fp, "%d %c %c %c\n", &map->rows,
				&map->empty, &map->obstacle, &map->full) != 4)
		return (0);
	return (1);
}

Map	*load_map(const char *filename)
{
	FILE	*fp = fopen(filename, "r");
	if (!fp)
		return NULL;
	
	Map * map = calloc(1, sizeof(Map));
	if (!map)
	{
		fclose(fp);
		return NULL;
	}

	if (!parse_header(fp, map))
	{
		fclose(fp);
		free(map);
		return NULL;
	}

	map->grid = calloc(map->rows, sizeof(char *));
	if (!map->grid)
	{
		fclose(fp);
		free(map);
		return NULL;
	}
	
	size_t len = 0;
	ssize_t read;
	char * line = NULL;

	int	row = 0;
	while((read = getline(&line, &len, fp)) != -1 && row < map->rows)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		map->cols = strlen(line);
		map->grid[row] = strdup(line);
		row++;
	}
	free(line);
	fclose(fp);
	
	if (row != map->rows)
	{
		free_map(map);
		return NULL;
	}

	return map;
}

Map	*load_map_stdin(void)
{
	Map * map = calloc(1, sizeof(Map));
	if (!map)
		return NULL;
	
	if (!parse_header(stdin, map))
	{
		free(map);
		return NULL;
	}

	map->grid = calloc(map->rows, sizeof(char *));
	if (!map->grid)
	{
		free(map);
		return NULL;
	}
	
	size_t len = 0;
	ssize_t read;
	char * line = NULL;

	int	row = 0;
	while((read = getline(&line, &len, stdin)) != -1 && row < map->rows)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		map->cols = strlen(line);
		map->grid[row] = strdup(line);
		row++;
	}
	free(line);
	
	if (row != map->rows)
	{
		free_map(map);
		return NULL;
	}

	return map;
}

void	free_map(Map *map)
{
	if (!map) return;
	if (map->grid)
	{
		for	(int i = 0; i < map->rows; i++)
			free(map->grid[i]);
		free(map->grid);
	}
	free(map);
}

void	print_map(Map *map)
{
	for	(int i = 0; i < map->rows; i++)
	{
		fputs(map->grid[i], stdout);
		fputc('\n', stdout);
	}
}

int	validate_map(Map *map)
{
	if (!map || !map->grid)
		return 0;
	
	if (map->rows <= 0 || map->cols <= 0)
		return 0;
	
	if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
		return 0;
	
	int	expected_cols = strlen(map->grid[0]);
	for	(int i = 0; i < map->rows; i++)
	{
		if ((int)strlen(map->grid[i]) != expected_cols)
			return 0;

		for	(int j = 0; j < expected_cols; j++)
		{
			char c = map->grid[i][j];
			if (c != map->empty && c != map->obstacle && c != map->full)
				return 0;
		}
	}
	map->cols = expected_cols;
	return 1;
}

void	solve_map(Map *map)
{
	if (!map || !map->grid) return;

	int rows = map->rows;
	int cols = map->cols;

	int	**dp = (int **)malloc(rows * sizeof(int *));
	for	(int i = 0; i < rows; i++)
		dp[i] = (int *)calloc(cols, sizeof(int));
	
	int	max_size = 0;
	int max_i = 0, max_j = 0;

	for	(int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (map->grid[i][j] == map->empty)
			{	if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
				{
					int min_val = dp[i -1][j];
					if (dp[i][j - 1] < min_val) min_val = dp[i][j - 1];
					if (dp[i - 1][j - 1] < min_val) min_val = dp[i - 1][j - 1];
					dp[i][j] = 1 + min_val;
				}

				if (dp[i][j] > max_size)
				{
					max_size = dp[i][j];
					max_i = i;
					max_j = j;
				}
			}
			else
				dp[i][j] = 0;
		}
	}

	for (int i = max_i - max_size + 1; i <= max_i; i++)
	{
		for (int j = max_j - max_size + 1; j <= max_j; j++)
			map->grid[i][j] = map->full;
	}

	for (int i = 0; i < rows; i++)
		free(dp[i]);
	free(dp);
}
