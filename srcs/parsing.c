/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:22:45 by gavizet           #+#    #+#             */
/*   Updated: 2016/12/02 16:12:13 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetri				*create_tetri(void)
{
	static int		i = 0;
	t_vector		pos;
	t_tetri			*tetri;

	if (!(tetri = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	pos.y = 0;
	while (pos.y < 4)
	{
		pos.x = 0;
		while (pos.x < 4)
		{
			tetri->block[pos.y][pos.x] = 0;
			pos.x++;
		}
		pos.y++;
	}
	tetri->letter = 'A' + i++;
	return (tetri);
}

t_tetri				*get_origin(t_tetri *tetri)
{
	t_vector		min;
	t_vector		max;
	int				count;

	min.y = 5;
	min.x = 5;
	max.y = 0;
	max.x = 0;
	count = 0;
	while (count < 4)
	{
		if (tetri->shape[count].x < min.x)
			min.x = tetri->shape[count].x;
		if (tetri->shape[count].y < min.y)
			min.y = tetri->shape[count].y;
		if (tetri->shape[count].x > max.x)
			max.x = tetri->shape[count].x;
		if (tetri->shape[count].y > max.y)
			max.y = tetri->shape[count].y;
		count++;
	}
	tetri->origin = min;
	tetri->size.x = max.x - min.x;
	tetri->size.y = max.y - min.y;
	return (tetri);
}

t_tetri				*new_tetri(const char *sample)
{
	t_vector		pos;
	t_tetri			*tetri;

	if (!(tetri = create_tetri()))
		return (NULL);
	pos.y = 0;
	while (pos.y < 4)
	{
		pos.x = 0;
		while (pos.x < 4)
		{
			if (*sample != '.' && *sample != '#')
				return (NULL);
			if (*(sample++) == '#')
				tetri->block[pos.y][pos.x] = 1;
			pos.x++;
		}
		if (*(sample++) != '\n')
			return (NULL);
		pos.y++;
	}
	if (!(check_tetri(tetri)))
		return (NULL);
	tetri = get_origin(tetri);
	return (tetri);
}

int					get_sample(int fd, char **sample)
{
	static int		lines = 0;
	char			*buff;
	int				i;

	if (lines > 104)
		return (-1);
	i = 0;
	*sample = ft_strnew(5 * 4);
	while (i++ < 4)
	{
		lines++;
		if (get_next_line(fd, &buff) > 0)
		{
			buff = ft_strjoin(buff, "\n");
			if (ft_strlen(buff) == 5)
				ft_strcat(*sample, buff);
			else
				return (-1);
		}
		else
			return (-1);
	}
	return (1);
}

t_tetri				**get_tetri_list(const char *file)
{
	int				fd;
	char			*sample;
	int				ret_val;
	t_tetri			**tetri;
	int				index;

	index = 0;
	ret_val = 1;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	tetri = (t_tetri**)ft_memalloc(sizeof(t_tetri*) * 27);
	while (ret_val && (ret_val = get_sample(fd, &sample)))
	{
		if (ret_val == -1)
			return (NULL);
		if (!(tetri[index] = new_tetri(sample)))
			return (NULL);
		ret_val = get_next_line(fd, &sample);
		if (ret_val && *sample)
			return (NULL);
		index++;
	}
	if (close(fd) == -1)
		return (NULL);
	return (tetri);
}
