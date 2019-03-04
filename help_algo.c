/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:00:05 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/03/04 15:00:06 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		result(t_str *gen)
{
	ft_printf("%d %d\n", gen->got_y, gen->got_x);
}

int			put_fig(int row, int col, t_str *gen)
{
	gen->count = 0;
	gen->y1 = 0;
	while (gen->fig[gen->y1])
	{
		gen->x1 = 0;
		while (gen->fig[gen->y1][gen->x1])
		{
			if (gen->fig[gen->y1][gen->x1] == '*')
			{
				if (row + gen->y1 >= gen->row || row + gen->y1 < 0 ||
				col + gen->x1 < 0 || col + gen->x1 >= gen->col)
					return (0);
				if (gen->map[row + gen->y1][col + gen->x1] == gen->opponent)
					return (0);
				if (gen->map[row + gen->y1][col + gen->x1] == gen->me)
					gen->count++;
			}
			gen->x1++;
		}
		gen->y1++;
	}
	if (gen->count == 1)
		return (1);
	return (0);
}

int			initthisshit(t_str *gen)
{
	int		prev;
	int		curr;

	gen->y = gen->cor_y;
	gen->x = gen->cor_x;
	prev = ft_abs((gen->got_y - gen->start_eny) +
	(gen->got_x - gen->start_enx));
	curr = ft_abs((gen->start_eny - gen->y) + (gen->start_enx - gen->x));
	if (curr < prev)
	{
		result(gen);
		return (1);
	}
	return (0);
}

int			ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}
