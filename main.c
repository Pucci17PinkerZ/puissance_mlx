#include "puissance_4.h"

int main(void)
{
	t_game	game;

	hello_player(void);
	if (ask_size_grid(&game))
		return (printf("pas good frrr"));
	set_grid_zero();
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
			return (perror("allocation error"), free_tab(game->grid, i), 1);
		i++;
	}
	return (0);
}

//fonction de clean
char **free_tab(int **grid, int i)
{
	while (i > 0)
	{
		free(game->grid[i]);
		i--;
	}
	free[game->grid];
	return (NULL);
}

char **set_grid_zero(int **grid, int row, int column)
{
	int i;
	int j;

	i = row;
	j = column;
	while (game->grid[i])
	{
		while (game->grid[i][j])
		{
			game->grid[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	return (game->grid);
}

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