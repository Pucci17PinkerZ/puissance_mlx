

int main(void)
{
	t_game	game;

	hello_player(void);
	if (ask_size_grid(&game))
		return (printf("pas good frrr"));
}


int	ask_size_grid(t_game *game)
{
	int	i;

	i = 0;
	printf("quelle taille de grille voulez vous?\n");
	printf("colonne: (MIN 7 | MAX 16 )\n");
	scanf("%d\n", game->row);
	printf("ligne: (MIN 6 | MAX 15 )\n");
	scanf("%d\n", game->column);
	if (check_grid_size(game->column, game->row))
		return (perror("size_grid_is_valid"), 1);
	game->grid = malloc(sizeof(int *) * (game->row + 1));
	if (!game->grid)
		return (1);
	while (game->grid[i])
	{
		game->grid[i] = malloc(sizeof(int) * (game->column + 1));
		if (!game->grid[i])
			return (perror("malloc"), free_tab(), 1);
	}
	return (0);
}

//fonction de clean

int	check_grid_size(int column, int row)
{
	if (row < 7 || row > 16)
		return (1);
	if (column < 6 || row > 15)
		return (1);
}


void	hello_player(void)
{
	printf("//////////////////////////////////////////////////\n");
	printf("/                 BIENVENUE !!!!                 /\n");
	printf("/                                                /\n");
	printf("/                                                /\n");
	printf("/                                                /\n");
	printf("/                                                /\n");
	printf("//////////////////////////////////////////////////\n");
	printf("\n");
}