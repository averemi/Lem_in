/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:40:42 by averemii          #+#    #+#             */
/*   Updated: 2018/03/07 20:40:45 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "./libft/libft.h"

typedef struct s_link	t_link;
typedef struct s_room	t_room;
typedef struct s_lemin	t_lemin;
typedef struct s_way	t_way;

struct					s_link
{
	char				*link1;
	char				*link2;
	int					unlinked;
	int					linklevel1;
	int					linklevel2;
	t_link				*next;
};

struct					s_room
{
	char				*name;
	long int			x;
	long int			y;
	t_room				*next;
	int					lvl;
};

struct					s_way
{
	char				*room;
	unsigned long long	ant;
	int					antfree;
	t_way				*next;
};

struct					s_lemin
{
	char				*s;
	int					antflag;
	int					linkflag;
	int					startendflag;
	unsigned long		ants;
	int					x;
	int					y;
	int					startflag;
	int					startflag2;
	int					endflag;
	int					endflag2;
	char				**str;
	int					rflag;
	t_room				*r;
	t_link				*l;
	char				*start;
	char				*end;
	long int			xstart;
	long int			ystart;
	long int			xend;
	long int			yend;
	int					startendlink;
	int					startendlink2;
	int					startlink;
	int					endlink;
	int					lvl;
	char				**way;
	int					flagforend;
	t_way				*waystr;
	int					antflag2;
	int					count;
};

void					ft_lemin(t_lemin *lm);
void					ft_display_input(t_lemin *lm);
void					ft_display_room_n_links(t_lemin *lm);
void					ft_rescue_ants(t_lemin *lm);
void					ft_rescue_ants2(t_way *w, t_lemin *lm);
int						ft_ant_recursion(char *way, t_lemin *lm, int i);
int						ft_make_end(t_lemin *lm);
void					ft_struct_way(t_lemin *lm);
void					ft_show_way(t_lemin *lm);
int						ft_save_way(t_lemin *lm);
int						ft_save_way3(t_link *ltmp, t_lemin *lm);
int						ft_save_way2(t_link *ltmp, t_lemin *lm);
void					ft_correct_way(int lvl, char *link, t_lemin *lm);
char					*ft_find_path(int lvl, char *link, t_lemin *lm);
void					ft_find_quickest(t_lemin *lm);
void					ft_find_quickest0(t_link *ltemp2, t_link *ltemp,
						t_lemin *lm);
int						ft_find_quickest3(t_link *ltemp2, t_link *ltemp,
						t_lemin *lm);
void					ft_make_last_level(t_lemin *lm);
void					ft_link_data(t_lemin *lm);
void					ft_check_coord(t_lemin *lm);
int						ft_no_lvl(t_lemin *lm);
int						ft_take_room(t_lemin *lm, char *s);
int						ft_take_room3(t_link *ltemp, t_lemin *lm,
						t_room *rt, char *s);
int						ft_take_room2(t_link *ltemp, t_lemin *lm,
						t_room *rt, char *s);
void					ft_make_first_level(char *s, t_lemin *lm);
void					ft_create_first_lvl(char *s, t_lemin *lm);
void					ft_level_maker(t_room *rtemp, t_lemin *lm);
void					ft_create_lvl(char *s, t_lemin *lm, int i);
void					ft_link_levels(t_lemin *lm, int i, char *s);
int						ft_create_room(t_lemin *lm);
void					ft_create_room2(char **s, t_lemin *lm);
void					ft_coord(t_room *rt, t_lemin *lm);
void					ft_create_room5(t_lemin *lm, char **s);
void					ft_create_room4(t_lemin *lm, char **s);
void					ft_create_room3(t_lemin *lm);
int						ft_check_end(char **s, t_room *rt2, t_lemin *lm);
void					ft_check_end2(char **s, t_lemin *lm);
void					ft_check_end3(t_lemin *lm);
int						ft_check_start(char **s, t_room *rt1, t_lemin *lm);
void					ft_check_start3(t_lemin *lm);
void					ft_check_start2(char **s, t_lemin *lm);
void					ft_check_number(char **s, t_lemin *lm);
int						ft_room(t_lemin *lm);
void					ft_room2(char *t, int i, t_lemin *lm);
int						ft_link(t_lemin *lm);
void					ft_create_link(t_lemin *lm);
void					ft_check_number_links(char **s, t_lemin *lm);
void					ft_create_link2(t_lemin *lm, t_link *lt, t_link lt2);
int						ft_check_link(t_lemin *lm, t_link lt2);
int						ft_check_lte(t_link lt2, t_link *lte);
int						ft_count_i(int i);
int						ft_check_startend(t_link lt2, t_lemin *lm);
int						ft_startend(t_lemin *lm);
void					ft_startend3(t_lemin *lm);
void					ft_startend2(t_lemin *lm);
int						ft_ant(t_lemin *lm);
void					ft_check_ants_num(t_lemin *lm);
int						ft_comment(t_lemin *lm);
int						ft_comment3(t_lemin *lm);
int						ft_comment2(t_lemin *lm);
void					ft_error2(t_lemin *lm);
void					ft_error(t_lemin *lm);
void					ft_make_free2(t_lemin *lm);
void					ft_remove_s(char **s);
void					ft_make_free(t_lemin *lm);
void					ft_free_way(t_lemin *lm);
void					ft_free_waystr(t_lemin *lm);
void					ft_free_str(t_lemin *lm);
void					ft_free_link(t_lemin *lm);
void					ft_free_room(t_lemin *lm);
long int				ft_atoi_lemin(const char *str);
void					ft_create_struct(t_lemin *lm);
void					ft_create_struct2(t_lemin *lm);

#endif
