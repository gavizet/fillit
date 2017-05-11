/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:22:47 by gavizet           #+#    #+#             */
/*   Updated: 2017/04/12 15:09:31 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int					clear_tetri(t_grid **grid, t_tetri *tetri)
{
	t_vector		pos;

	pos.y = 0;
	while (pos.y <= (*grid)->prev_pos.y)
	{
		pos.x = 0;
		while (pos.x <= (*grid)->prev_pos.x)
		{
			if ((*grid)->square[pos.y][pos.x] == tetri->letter)
				(*grid)->square[pos.y][pos.x] = '.';
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}

int					put_tetri(t_grid **grid, t_tetri *tetri, t_vector pos)
{
	int				i;

	i = 0;
	while (i < 4)
	{
		if (!((*grid)->square[tetri->shape[i].y - tetri->origin.y + pos.y]
							[tetri->shape[i].x -
							tetri->origin.x + pos.x] == '.'))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*grid)->square[tetri->shape[i].y - tetri->origin.y + pos.y]
						[tetri->shape[i].x -
						tetri->origin.x + pos.x] = tetri->letter;
		i++;
	}
	return (1);
}

void				clear_grid(t_grid **grid)
{
	t_vector		pos;

	pos.y = 0;
	while (pos.y < (*grid)->prev_pos.y)
	{
		pos.x = 0;
		while (pos.x < (*grid)->prev_pos.x)
		{
			(*grid)->square[pos.y][pos.x] = '.';
			pos.x++;
		}
		pos.y++;
	}
}

int					resolve(t_grid **grid, t_tetri **tetri)
{
	t_vector		pos;

	if (!(*tetri))
		return (1);
	pos.y = 0;
	while (pos.y <= (*grid)->prev_pos.y - (*tetri)->size.y)
	{
		pos.x = 0;
		while (pos.x <= (*grid)->prev_pos.x - (*tetri)->size.x)
		{
			if (put_tetri(grid, *tetri, pos))
			{
				if (resolve(grid, tetri + 1))
					return (1);
				else
					clear_tetri(grid, *tetri);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

void				final_solve(t_grid **grid, t_tetri **tetri)
{
	*grid = create_grid(*grid);
	while (!resolve(grid, tetri))
	{
		clear_grid(grid);
		(*grid)->prev_pos.y++;
		(*grid)->prev_pos.x++;
	}
}
