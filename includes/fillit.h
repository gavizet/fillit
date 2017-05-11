/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:41:37 by gavizet           #+#    #+#             */
/*   Updated: 2017/04/12 15:17:03 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct	s_tetri
{
	int			block[4][4];
	t_vector	origin;
	t_vector	shape[4];
	t_vector	size;
	char		letter;
}				t_tetri;

typedef struct	s_grid
{
	char		**square;
	t_vector	prev_pos;
}				t_grid;

int				check_tetri(t_tetri *tetri);
t_grid			*create_grid(t_grid *grid);
t_tetri			**get_tetri_list(const char *file);
int				resolve(t_grid **grid, t_tetri **tetri);
void			final_solve(t_grid **grid, t_tetri **tetri);

#endif
