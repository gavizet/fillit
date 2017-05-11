/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:23:04 by gavizet           #+#    #+#             */
/*   Updated: 2016/12/02 16:12:28 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_connect(t_tetri *tetri)
{
	t_vector	pos;
	t_vector	connect;

	pos.x = -1;
	connect.y = 0;
	while (++pos.x < 4)
	{
		pos.y = -1;
		connect.x = 0;
		while (++pos.y < 4)
			if ((tetri->shape[pos.x].x + 1 == tetri->shape[pos.y].x &&
				tetri->shape[pos.x].y == tetri->shape[pos.y].y) ||
				(tetri->shape[pos.x].x - 1 == tetri->shape[pos.y].x &&
				tetri->shape[pos.x].y == tetri->shape[pos.y].y) ||
				(tetri->shape[pos.x].x == tetri->shape[pos.y].x &&
				tetri->shape[pos.x].y + 1 == tetri->shape[pos.y].y) ||
				(tetri->shape[pos.x].x == tetri->shape[pos.y].x &&
				tetri->shape[pos.x].y - 1 == tetri->shape[pos.y].y))
				connect.x++;
		connect.y = (connect.x > 1) ? 1 : connect.y;
		if (!connect.x)
			return (0);
	}
	return (connect.y);
}

int		check_tetri(t_tetri *tetri)
{
	int			i;
	t_vector	pos;
	int			block;

	i = 0;
	block = 0;
	pos.x = -1;
	pos.y = -1;
	while (++pos.y < 4)
	{
		while (++pos.x < 4)
		{
			if (tetri->block[pos.y][pos.x])
			{
				tetri->shape[i++] = pos;
				block++;
			}
			if (i > 4)
				return (0);
		}
		pos.x = -1;
	}
	if (block != 4)
		return (0);
	return (check_connect(tetri));
}
