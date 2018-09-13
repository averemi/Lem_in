/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:31:17 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:31:34 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_save_way2(t_link *ltmp, t_lemin *lm)
{
	ft_correct_way(ltmp->linklevel2, ltmp->link2, lm);
	return (1);
}

int		ft_save_way3(t_link *ltmp, t_lemin *lm)
{
	ft_correct_way(ltmp->linklevel1, ltmp->link1, lm);
	return (1);
}

int		ft_save_way(t_lemin *lm)
{
	t_link *ltmp;

	ltmp = lm->l;
	while (ltmp)
	{
		if (ft_strcmp(lm->end, ltmp->link1) == 0)
		{
			if ((ltmp->unlinked == 0 && ltmp->linklevel2 != 0 &&
				ft_strcmp(lm->start, ltmp->link2) != 0) ||
				(ltmp->unlinked == 0 && ltmp->linklevel2 == 0 &&
				(ft_strcmp(lm->start, ltmp->link2) == 0)))
				return (ft_save_way2(ltmp, lm));
		}
		else if (ft_strcmp(lm->end, ltmp->link2) == 0)
		{
			if ((ltmp->unlinked == 0 && ltmp->linklevel1 != 0
				&& ft_strcmp(lm->start, ltmp->link1) != 0) ||
				(ltmp->unlinked == 0 && ltmp->linklevel1 == 0
				&& (ft_strcmp(lm->start, ltmp->link1) == 0)))
				return (ft_save_way3(ltmp, lm));
		}
		ltmp = ltmp->next;
	}
	ft_error(lm);
	return (0);
}

void	ft_struct_way(t_lemin *lm)
{
	t_way	*w;
	int		i;

	i = 0;
	while (lm->way[i] != NULL)
		i++;
	i--;
	while (i >= 0)
	{
		w = lm->waystr;
		while (w)
			w = w->next;
		w = (t_way *)malloc(sizeof(t_way));
		w->room = ft_strdup(lm->way[i]);
		w->ant = 0;
		w->antfree = 0;
		w->next = lm->waystr;
		lm->waystr = w;
		i--;
	}
}

void	ft_show_way(t_lemin *lm)
{
	t_way	*way;
	int		i;

	i = 0;
	way = lm->waystr;
	while (way)
	{
		if (way->ant != 0 && ft_strcmp(lm->start, way->room) != 0)
		{
			ft_putstr("L");
			ft_putnbr(way->ant);
			ft_putstr("-");
			ft_putstr(way->room);
			if (way->next && way->next->ant != 0)
				ft_putstr(" ");
			i = 1;
		}
		way = way->next;
	}
	if (i == 1)
		ft_putstr("\n");
}
