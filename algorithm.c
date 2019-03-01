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
	int		k;

	k = 0;
	fig_row = -gen->y_fig;
	count = -1;
	while (gen->row > fig_row)
	{
		fig_col = -gen->y_fig;
		while (gen->col > fig_col)
		{
			if (put_figure(fig_row, fig_col, gen))
			{
				if(work_with_len(gen, fig_row, fig_col) > count)
				{
					count = work_with_len(gen, fig_row, fig_col);
					gen->got_y = fig_row;
					gen->got_x = fig_col;
				}
			}
			fig_col++;
		}
		fig_row++;
	}
	gen->y = fig_row;
	gen->x = fig_col;
	return (count);
}

int			solve_2(t_str *gen)
{
	int		fig_row;
	int		fig_col;
	int		count;

	fig_row = -gen->y_fig;
	count = -1;
	while (gen->row > fig_row)
	{
		fig_col = -gen->y_fig;
		while (gen->col > fig_col)
		{
			if (put_figure(fig_row, fig_col, gen))
			{
				count++;
				gen->got_y = fig_row;
				gen->got_x = fig_col;
			}
			fig_col++;
		}
		fig_row++;
	}
	gen->y = fig_row;
	gen->x = fig_col;
	return (count);
}


int			work_with_len(t_str *gen, int fig_row, int fig_col)
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

void		result(t_str *gen)
{
	ft_printf("%d %d\n", gen->got_y, gen->got_x);

}

int			put_figure(int row, int col, t_str *gen)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (gen->fig[i])
	{
		j = 0;
		while (gen->fig[i][j])
		{
			if (gen->fig[i][j] == '*')
			{
				if (row + i >= gen->row || row + i < 0||
					col + j < 0 || col + j >= gen->col)
					return (0);
				if ((gen->map[row + i][col +j] == gen->opponent ||
				 gen->map[row + i][col +j] == gen->opponent + 32))
					return (0);
				if ((gen->map[row + i][col + j] == gen->me ||
				gen->map[row + i][col + j] == gen->me + 32))
					count++;
			}
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

