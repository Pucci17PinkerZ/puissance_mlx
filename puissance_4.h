#ifndef PUISSANCE_4_H
# define PUISSANCE_4_H


# include <stdio.h>

typedef	struct s_sprite
{
	void		*img_coin_red;
	void		*img_coin_yellow;
	void		*img_wall_empty;
	void		*img_wall_red;
	void		*img_wall_yellow;

}	t_sprite;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
}	t_mlx;

typedef	struct s_game
{
	char		**grid;
	int			column;
	int			row;
	bool		red_play;
	bool		is_winning;
	t_mlx		*mlx;
	t_sprite	*sprt;
}	t_game;


int		ask_size_grid(t_game *game);
int		check_grid_size(int column, int row);
void	hello_player(void);

#endif