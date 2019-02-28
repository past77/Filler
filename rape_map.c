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
				gen->start_mex = i;
				gen->start_mey = j;
			}
			if (ft_toupper(gen->map[i][j]) == gen->opponent)
			{
				gen->start_enx = i;
				gen->start_eny = j;
			}
			j++;
		}
		i++;
	}
}

void		rape_map(t_str *gen)
{
	printf("%s\n","string in rape" );
	if (gen->quarter == 0)
		get_quarter(gen);
	printf("quater: %d\n", gen->quarter);
	if (solve_1(gen) > 0)
	{
		printf("%s\n", "in solve_1" );
		result(gen);
		return ;
		//if (check_algo(gen) == 1)
		//{

		//}
	}

}
