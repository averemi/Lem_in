/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:33:35 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:33:39 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_no_lvl(t_lemin *lm)
{
	t_room *rtemp;

	rtemp = lm->r;
	while (rtemp)
	{
		if (rtemp->lvl == lm->lvl && ft_take_room(lm, rtemp->name))
			return (1);
		rtemp = rtemp->next;
	}
	return (0);
}

void	ft_check_coord(t_lemin *lm)
{
	t_room *rm;
	t_room *rmbig;

	rmbig = lm->r;
	while (rmbig)
	{
		rm = lm->r;
		while (rm)
		{
			if ((rmbig->x == rm->x && rmbig->y == rm->y &&
				ft_strcmp(rmbig->name, rm->name) != 0)
				|| (rm->x == lm->xstart && rm->y == lm->ystart &&
					ft_strcmp(rm->name, lm->start) != 0)
				|| (rm->x == lm->xend && rm->y == lm->yend &&
					ft_strcmp(rm->name, lm->end) != 0))
				ft_error(lm);
			rm = rm->next;
		}
		rmbig = rmbig->next;
	}
}

void	ft_link_data(t_lemin *lm)
{
	t_room *rtemp;

	if ((lm->startflag2 == 2 && lm->endflag2 == 2 &&
		lm->startlink == 1 && lm->endlink == 1) ||
		(lm->startflag2 == 2 && lm->endflag2 == 2 && lm->startendlink2 == 1))
	{
		ft_check_coord(lm);
		ft_make_first_level(lm->start, lm);
		while (ft_no_lvl(lm))
		{
			rtemp = lm->r;
			while (rtemp)
			{
				if (rtemp->lvl == lm->lvl)
					ft_level_maker(rtemp, lm);
				rtemp = rtemp->next;
			}
			lm->lvl = lm->lvl + 1;
		}
	}
	else
		ft_error(lm);
}

void	ft_make_last_level(t_lemin *lm)
{
	t_link *ltemp;

	ltemp = lm->l;
	while (ltemp)
	{
		if (ft_strcmp(ltemp->link1, lm->end) == 0)
			ltemp->linklevel1 = -100;
		else if (ft_strcmp(ltemp->link2, lm->end) == 0)
			ltemp->linklevel2 = -100;
		ltemp = ltemp->next;
	}
}
