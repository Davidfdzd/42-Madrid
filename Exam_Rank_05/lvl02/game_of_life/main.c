#include "game_of_life.h"

int	main(int argc, char **argv)
{
	if (argc < 4) return 1;

	int w = atoi(argv[1]);
	int h = atoi(argv[2]);
	int it = atoi(argv[3]);

	Board	*b = create_board(w, h);
	if (!b) return 1;

	process_input(b);

	for	(int i = 0; i < it; i++)
		simulate(b);

	print_board(b);
	free_board(b);

	return (0);
}

