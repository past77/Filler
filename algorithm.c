/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:47:53 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/02/24 17:47:54 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int			solve_quater1(t_str *gen)
{
	int		row;
	int		col;
	int		k;

	gen->got_x = 0;
	gen->got_y = 0;
	row = gen->row;
	k = 0;
	while (row > 0)
	{
		col = gen->col;
		while (col > 0)
		{
			k = put_figure(row, col, gen);
			if (k == 1)
			{
				result(gen);
				return (0);
			}
			col--;
		}
		row--;
	}
	return (1);
}

void		result(t_str *gen)
{
	ft_printf("%d %d\n",gen->got_y, gen->got_x);
	gen->start_mex = gen->got_x;
	gen->start_mey = gen->got_y;
}

int			put_figure(int row, int col, t_str *gen)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	if (row + gen->y_fig > gen->row || col + gen->x_fig > gen->col)
		return (0);
	while (++i <= (gen->y_fig - 1))
	{
		j = -1;
		while (++j <= (gen->x_fig - 1))
		{
			if (gen->fig[i][j] == '*' && (gen->map[row + i][col +j] == gen->opponent))
				return (0);
			if (gen->fig[i][j] == '*' && (gen->map[row + i][col + j] == gen->me))
				count++;
		}
	}
	if (count == 1)
	{
		gen->got_x = col;
		gen->got_y = row;
		return (1);
	}
	return (0);
}

int			solve(t_str *gen)
{
	if (gen->quarter == 1)
	{
		if (solve_quater1(gen) == 1)
			return (1);
	}
	return (0);
}
