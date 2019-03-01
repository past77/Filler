/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rape_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:02:48 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/02/22 17:02:49 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_quarter(t_str *gen)
{
	int i;
	int j;

	i = 0;
	while (gen->map[i])
	{
		j = 0;
		while (gen->map[i][j])
		{
			if (ft_toupper(gen->map[i][j]) == gen->me)
			{
				if (i <= gen->row / 2 && j <= gen->col / 2)
					gen->quarter = 1;
				else if (i <= gen->row /2 && j >= gen->col / 2)
					gen->quarter = 2;
				else if (i >= gen->row / 2 && j <= gen->col / 2)
					gen->quarter = 3;
				else
					gen->quarter = 4;
				break;
			}
			j++;
		}
		i++;
	}
}

void	start_cord(t_str *gen)
{
	int i;
	int j;

	i = 0;
	while (gen->map[i])
	{
		j = 0;
		while (gen->map[i][j])
		{
			if (ft_toupper(gen->map[i][j]) == gen->me)
			{
				gen->start_mex = j;
				gen->start_mey = i;
			}
			if (ft_toupper(gen->map[i][j]) == gen->opponent)
			{
				gen->start_enx = j;
				gen->start_eny = i;
			}
			j++;
		}
		i++;
	}
}

void		rape_map(t_str *gen)
{
	//int		prev;
	//int		curr;


	if (gen->quarter == 0)
		get_quarter(gen);

	if (solve_2(gen))
	{
		printf("eny: %d  enx: %d\n", gen->start_eny ,gen->start_enx);
		//prev = ft_abs((gen->got_y - gen->start_eny) + (gen->got_x - gen->start_enx));
		////curr = ft_abs((gen->start_eny - gen->y) + (gen->start_enx - gen->x));
		//if (curr < prev)
			result(gen);
		return ;
	}
	if (solve_1(gen))
	{
		//prev = ft_abs((gen->got_y - gen->start_eny) + (gen->got_x - gen->start_enx));
		//curr = ft_abs((gen->start_eny - gen->y) + (gen->start_enx - gen->x));
		//if (curr < prev)
			result(gen);
		return ;
	}
}
