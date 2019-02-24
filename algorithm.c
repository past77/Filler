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
	int		i;
	int		j;
	int		k;

	i = gen->row;
	k = 0;
	while (i > 0)
	{
		j = gen->col;
		while (j > 0)
		{
			k = put_figure(i, j, gen);
			if (k = 0)
			{
				result(gen);
				return (0);
			}
			j--;
		}
		i--;
	}
	return (1);
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
