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

#ifndef FILLER_H
# define FILLER_H
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"
# include "./libft/ft_printf/ft_printf.h"

typedef struct	s_str
{
	char		me;
	char		opponent;
	char		ex;
	int			row;
	int			col;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			count;
	int			cor_x;
	int			cor_y;
	int			x_fig;
	int			y_fig;
	int			start_x_fig;
	int			start_y_fig;
	int			end_x_fig;
	int			end_y_fig;
	char		**fig;
	char		**map;
	int			quarter;
	int			start_mex;
	int			start_mey;
	int			start_enx;
	int			start_eny;
	int			tx_fig;
	int			ty_fig;
	int			got_x;
	int			got_y;
	int			fd;
}				t_str;

int				initthisshit(t_str *gen);
void			initialize_struct(t_str *gen);
void			find_players(t_str *str);
void			find_map_size(t_str *gen);
void			parse_map(t_str *gen);
void			parse_fig(t_str *gen);
void			find_fig(t_str *gen);
void			get_quarter(t_str *gen);
void			start_cord(t_str *gen);
void			rape_map(t_str *gen);
int				solve_quater1(t_str *gen);
int				solve(t_str *gen);
int				put_figure(int row, int col, t_str *gen);
void			result(t_str *gen);
void			ft_tabdel(char ***tab, int count);
int				solve_3(t_str *gen);
int				work_vertical(t_str *gen, int fig_row, int fig_col);
int				put_fig(int row, int col, t_str *gen);
int				solve_1(t_str *gen);
int				solve_2(t_str *gen);
int				solve_sup(t_str *gen, int count);
int				work_horizon(t_str *gen, int fig_row, int fig_col);

#endif
