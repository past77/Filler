/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:06:12 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/02/20 18:06:13 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_F_H
# define FILLER_F_H
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"
# include "./libft/ft_printf/ft_printf.h"


typedef struct	s_str
{
	char		me;
	char		opponent;
	int			row;
	int			col;
	int			x;
	int			y;
	int			cor_x;
	int			cor_y;
	int			x_fig;
	int			y_fig;
	char		**fig;
	char		**map;
}				t_str;

int				fd;




void			initialize_struct(t_str *gen);
void			find_players(t_str *str);
void			find_map_size(t_str *gen);
void			parse_map(t_str *gen);
void			parse_fig(t_str *gen);
void			find_fig(t_str *gen);


void	clear_split(char **str);

#endif
