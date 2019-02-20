/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:56:00 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/02/20 17:56:01 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		initialize_struct(t_str *gen)
{
	gen->me = '/0';
	gen->opponent = '/0';
	gen->row = 0;
	gen->col = 0;
	gen->x = 0;
	gen->y = 0;
	fd = 0;
}

void		find_players(t_str *str)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	get_next_line(fd, &line);
	while (line[i])
	{
		if (line[i] == 'p')
		{
			if (line[i + 1] == '1')
				gen->me = 'O';
			else
				gen->me = 'X';
			break;
		}
		i++;
	}
	gen->opponent = gen->me == 'X' ? 'O' : 'X';
	ft_strdel(&line);
}

void		find_map_size(t_str *gen)
{
	int		i;
	char	*line;

	line = NULL;
	get_next_line(fd, &line);
	while (ft_isalpha(line[i]) || line[i] == ' ')
		i++;
	gen->row = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	gen->col = ft_atoi(line + i);
	ft_strdel(&line);
}

int			main(void)
{
	char	*line
	t_str	*gen;

	gen = (t_str *)malloc(sizeof(t_str));
	line = NULL;
	initialize_struct(gen);
	find_players(gen);
	find_map_size(gen);
	while

}
