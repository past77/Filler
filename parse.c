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
	}
	gen->map[j] = NULL;
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
	ft_del_strsplit(str);
	parse_fig(gen);
}

void	ft_del_strsplit(char **str) //!!!!!!!!!!!!
{
	size_t i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
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
	while (gen->row > i)
	{
		get_next_line(fd, &line);
		str = line;
		gen->fig[j++] = ft_strsub(line, 4, ft_strlen(line));
		free(str);
		i++;
	}
	gen->fig[j] = NULL;
}
