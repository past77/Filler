/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:56:00 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/03/04 14:48:38 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		initialize_struct(t_str *gen)
{
	gen->me = '\0';
	gen->opponent = '\0';
	gen->row = 0;
	gen->col = 0;
	gen->x = 0;
	gen->y = 0;
	gen->x_fig = 0;
	gen->y_fig = 0;
	gen->got_x = 0;
	gen->got_y = 0;
	gen->start_x_fig = 0;
	gen->start_y_fig = 0;
	gen->end_x_fig = 0;
	gen->end_y_fig = 0;
	gen->tx_fig = 0;
	gen->ty_fig = 0;
	gen->fig = NULL;
	gen->map = NULL;
	gen->quarter = 0;
	gen->start_mex = 0;
	gen->start_mey = 0;
	gen->start_enx = 0;
	gen->start_eny = 0;
	gen->fd = 0;
	gen->ex = '\0';
}

void		find_players(t_str *gen)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	get_next_line(gen->fd, &line);
	if (line[95] == 'j')
		gen->ex = 'S';
	while (line[i])
	{
		if (line[i] == 'p')
		{
			if (line[i + 1] == '1')
				gen->me = 'O';
			else
				gen->me = 'X';
			break ;
		}
		i++;
	}
	gen->opponent = gen->me == 'X' ? 'O' : 'X';
	ft_strdel(&line);
}

void		find_map_size(t_str *gen)
{
	char	*line;
	char	**str;

	line = NULL;
	get_next_line(gen->fd, &line);
	str = ft_strsplit(line, ' ');
	gen->row = ft_atoi(str[1]);
	gen->col = ft_atoi(str[2]);
	clear_split(str);
	ft_strdel(&line);
}

int			main(void)
{
	char	*line;
	t_str	*gen;

	gen = (t_str *)malloc(sizeof(t_str));
	line = NULL;
	initialize_struct(gen);
	find_players(gen);
	find_map_size(gen);
	while (get_next_line(gen->fd, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 7))
		{
			parse_map(gen);
			find_fig(gen);
			rape_map(gen);
		}
		else
			ft_strdel(&line);
	}
}
