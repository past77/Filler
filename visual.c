/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:54:52 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/03/03 14:54:53 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	main_part(t_str *gen, t_vis *vis)
{
	int	x;
	int	y;

	y = 0;
	while (gen->map[y])
	{
		x = 0;
		while (gen->map[y][x])
		{
			if (gen->map[y][x] == gen->opponent ||
				gen->map[y][x] == gen->opponent + 32)
				put_pix(vis, 0xfffff0, x, y);
			else if (gen->map[y][x] == gen->me ||
				gen->map[y][x] == gen->me + 32)
				put_pix(vis, 0xff7f, x, y);
			x++;
		}
		y++;
	}
}

void	put_pix(t_vis *vis, int color, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			mlx_pixel_put(vis->mlx_ptr, vis->win_ptr,
				25 + (x * 11) + j, 25 + (y * 11) + i, color);
			j++;
		}
		i++;
	}
}

void			data_for_vis(t_str *gen, t_vis *vis)
{
	vis->mlx_ptr = mlx_init();
	vis->height = gen->row * 25 + 0;
	vis->width = gen->col * 25 + 0;
	vis->win_ptr = mlx_new_window(vis->mlx_ptr, vis->width,
		vis->height, "Visual by Pablo Eskobar, sasit'");
	main_part(gen, vis);
}
