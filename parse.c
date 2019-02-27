/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:44:12 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/02/21 14:44:13 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		parse_map(t_str *gen)
{
	int		i;
	int		j;
	char	*line;
	char	*str;

	i = 0;
	line = NULL;
	j = 0;
	gen->map = (char **)malloc(sizeof(char *) * (gen->row + 1));
	while (gen->row > i)
	{
		get_next_line(fd, &line);
		str = line;
		gen->map[j++] = ft_strsub(line, 4, ft_strlen(line));
		free(str);
		i++;
		//ft_strdel(&line);
	}
	gen->map[j] = NULL;
	start_cord(gen);
}

void		find_fig(t_str *gen)
{
	char	*line;
	char	**str;

	line = NULL;
	get_next_line(fd, &line);
	str = ft_strsplit(line, ' ');
	gen->y_fig = ft_atoi(str[1]);
	gen->x_fig = ft_atoi(str[2]);
	clear_split(str);
	parse_fig(gen);
}

void		get_cord_fig(t_str *gen)
{
	int		i;
	int		j;

	i = 0;
	gen->start_x_fig = gen->x_fig;
	gen->start_y_fig = gen->y_fig;
	while (i < gen->y_fig)
	{
		j = -1;
		while (++j < gen->x_fig)
				if (gen->fig[i][j] == '*')
			{
				if (j < gen->start_x_fig)
					gen->start_x_fig = j;
				if (j > gen->end_x_fig)
					gen->end_x_fig = j;
				if (i < gen->start_y_fig)
					gen->start_y_fig = i;
				if (i > gen->end_y_fig)
					gen->end_y_fig = i;
			}
		i++;
	}
	gen->tfig_x = (gen->end_x_fig - gen->start_x_fig) + 1;
	gen->tfig_y = (gen->end_y_fig - gen->start_y_fig) + 1;
}

void		parse_fig(t_str *gen)
{
	int		i;
	int		j;
	char	*line;
	char	*str;

	i = 0;
	j = 0;
	line = NULL;
	gen->fig = (char **)malloc(sizeof(char *) * (gen->y_fig + 1));
	while (gen->y_fig > i)
	{
		get_next_line(fd, &line);
		str = line;
		gen->fig[j++] = ft_strdup(line);
		free(str);
		i++;
	}
	get_cord_fig(gen);
	gen->fig[j] = NULL;
}
