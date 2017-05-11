/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:23:50 by gavizet           #+#    #+#             */
/*   Updated: 2016/12/02 16:12:46 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_grid			*create_grid(t_grid *grid)
{
	t_vector	pos;

	pos.y = 0;
	pos.x = 0;
	grid = (t_grid*)ft_memalloc(sizeof(grid));
	grid->square = (char**)ft_memalloc(17 * sizeof(char*));
	while (pos.y < 16)
	{
		grid->square[pos.y] = ft_strdup("................");
		pos.y++;
	}
	grid->prev_pos.x = 1;
	grid->prev_pos.y = 1;
	return (grid);
}

void			print_result(t_grid *grid)
{
	t_vector	pos;

	pos.y = 0;
	while (pos.y <= grid->prev_pos.y)
	{
		pos.x = 0;
		while (pos.x <= grid->prev_pos.x)
		{
			ft_putchar(grid->square[pos.y][pos.x]);
			pos.x++;
		}
		ft_putchar('\n');
		pos.y++;
	}
}

int				main(int ac, char **av)
{
	t_tetri		**tetri;
	t_grid		*grid;

	if (ac != 2)
	{
		ft_putendl("usage: fillit file");
		return (-1);
	}
	if (!(tetri = get_tetri_list(av[1])))
	{
		ft_putendl("error");
		return (-2);
	}
	final_solve(&grid, tetri);
	print_result(grid);
	return (1);
}
