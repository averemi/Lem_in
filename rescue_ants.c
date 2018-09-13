/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescue_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:30:11 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:30:13 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_make_end(t_lemin *lm)
{
	t_way				*w;
	t_way				*w2;

	w2 = lm->waystr;
	while (w2)
	{
		w = lm->waystr;
		while (w)
		{
			if (w->ant == lm->ants && ft_strcmp(w->room, lm->end) != 0)
				w->ant = 0;
			else if (w->ant > 0 && w->ant != lm->ants)
				w->ant = w->ant + 1;
			else if (w->ant == lm->ants && ft_strcmp(w->room, lm->end) == 0)
				return (1);
			w = w->next;
		}
		ft_show_way(lm);
		w2 = w2->next;
	}
	return (0);
}

int		ft_ant_recursion(char *way, t_lemin *lm, int i)
{
	t_way				*w;

	w = lm->waystr;
	while (w)
	{
		if (ft_strcmp(way, w->room) == 0 && i == 1)
			return (1);
		if (w->ant != 0)
		{
			if (lm->ants >= w->ant + 1 && w->antfree == 0)
				w->ant = w->ant + 1;
			else if (((lm->ants < w->ant + 1) && (w->ant > 0))
				|| (w->antfree == 1 && w->ant > 0))
			{
				w->antfree = 1;
				w->ant = 0;
			}
		}
		w = w->next;
	}
	return (0);
}

void	ft_rescue_ants2(t_way *w, t_lemin *lm)
{
	if (w->ant == 0 && w->antfree == 0 && lm->flagforend == 0)
	{
		w->ant = 1;
		ft_ant_recursion(w->room, lm, 1);
	}
	else if (lm->flagforend == 1)
		ft_ant_recursion(w->room, lm, 2);
	ft_show_way(lm);
}

void	ft_rescue_ants(t_lemin *lm)
{
	unsigned long long	count;
	t_way				*w;
	unsigned long long	i;

	i = 0;
	count = 0;
	while (lm->way[count])
		count++;
	i = count + 1;
	while (i >= count)
	{
		w = lm->waystr;
		while (w)
		{
			ft_rescue_ants2(w, lm);
			w = w->next;
		}
		if (count <= lm->ants)
			lm->flagforend = 1;
		if (lm->flagforend == 0)
			break ;
		i = lm->waystr->ant;
	}
	ft_make_end(lm);
}
