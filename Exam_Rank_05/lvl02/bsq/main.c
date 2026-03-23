#include "bsq.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{	
		Map	*map = load_map_stdin();
		if (!map || !validate_map(map))
			fprintf(stderr, "map error\n");
		else
		{
			solve_map(map);
			print_map(map);
			free_map(map);
		}
	}
	else
	{
		for	(int i = 1; i < argc; i++)
		{
			Map	*map = load_map(argv[i]);
			if (!map || !validate_map(map))
				fprintf(stderr, "map_error\n");
			else
			{
				solve_map(map);
				print_map(map);
				free_map(map);
			}
			if (i < argc - 1)
				printf("\n");
		}
	}
	return (0);
}

