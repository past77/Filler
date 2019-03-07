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

int			solve_1(t_str *gen)
{
	int		fig_row;
	int		fig_col;
	int		count;

	fig_row = -gen->ty_fig;
	count = -1;
	while (gen->row > fig_row)
	{
		fig_col = -gen->ty_fig;
		while (gen->col > fig_col)
		{
			if (put_fig(fig_row, fig_col, gen))
			{
				if (work_horizon(gen, fig_row, fig_col) > count)
				{
					count = work_horizon(gen, fig_row, fig_col);
					gen->got_y = fig_row;
					gen->got_x = fig_col;
				}
			}
			fig_col++;
		}
		fig_row++;
	}
	return (count);
}

int			solve_3(t_str *gen)
{
	int		fig_row;
	int		fig_col;
	int		count;

	fig_row = -gen->ty_fig;
	count = -1;
	while (gen->row > fig_row)
	{
		fig_col = -gen->tx_fig;
		while (gen->col > fig_col)
		{
			if (put_fig(fig_row, fig_col, gen))
			{
				if (work_vertical(gen, fig_row, fig_col) > count)
				{
					count = work_vertical(gen, fig_row, fig_col);
					gen->got_y = fig_row;
					gen->got_x = fig_col;
				}
			}
			fig_col++;
		}
		fig_row++;
	}
	return (count);
}

int			solve_2(t_str *gen)
{
	int		count;

	gen->cor_y = -gen->y_fig;
	count = -1;
	while (gen->row > gen->cor_y)
	{
		gen->cor_x = -gen->x_fig;
		while (gen->col > gen->cor_x)
		{
			if (put_fig(gen->cor_y, gen->cor_x, gen))
			{
				count++;
				gen->got_y = gen->cor_y;
				gen->got_x = gen->cor_x;
				if (gen->quarter == 3 || gen->quarter == 4)
					return (1);
			}
			gen->cor_x++;
		}
		gen->cor_y++;
	}
	if (initthisshit(gen))
		return (0);
	return (count);
}

int			work_vertical(t_str *gen, int fig_row, int fig_col)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (gen->fig[i])
	{
		j = 0;
		while (gen->fig[i][j])
		{
			if (gen->fig[i][j] == '*')
			{
				if (j + fig_col == gen->start_mex &&
					gen->map[i + fig_row][j + fig_col] != gen->me)
					count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int			work_horizon(t_str *gen, int fig_row, int fig_col)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (gen->fig[i])
	{
		j = 0;
		while (gen->fig[i][j])
		{
			if (gen->fig[i][j] == '*')
			{
				if (i + fig_row == gen->start_mey &&
					gen->map[i + fig_row][j + fig_col] != gen->me)
					count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
