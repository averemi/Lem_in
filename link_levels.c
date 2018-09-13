/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_levels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:40:53 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:40:55 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_count_i(int i)
{
	if (i != 2)
		return (0);
	return (1);
}

int		ft_check_lte(t_link lt2, t_link *lte)
{
	if (((ft_strcmp(lt2.link1, lte->link2) == 0) &&
		(ft_strcmp(lt2.link2, lte->link1) == 0))
			|| ((ft_strcmp(lt2.link1, lte->link1) == 0)
				&& (ft_strcmp(lt2.link2, lte->link2) == 0)))
		return (1);
	return (0);
}

void	ft_link_levels(t_lemin *lm, int i, char *s)
{
	t_link	*ltemp;

	ltemp = lm->l;
	while (ltemp)
	{
		if (ft_strcmp(s, ltemp->link1) == 0)
			ltemp->linklevel1 = i;
		if (ft_strcmp(s, ltemp->link2) == 0)
			ltemp->linklevel2 = i;
		ltemp = ltemp->next;
	}
}

void	ft_create_lvl(char *s, t_lemin *lm, int i)
{
	t_room	*rt;

	rt = lm->r;
	while (rt)
	{
		if (rt->lvl == 0 && (ft_strcmp(rt->name, s) == 0))
		{
			rt->lvl = i;
			ft_link_levels(lm, i, s);
			break ;
		}
		rt = rt->next;
	}
}

void	ft_level_maker(t_room *rtemp, t_lemin *lm)
{
	t_link	*lt;
	int		i;

	lt = lm->l;
	i = lm->lvl;
	i++;
	while (lt)
	{
		if ((ft_strcmp(lt->link1, rtemp->name) == 0) ||
			ft_strcmp(lt->link2, rtemp->name) == 0)
		{
			if (ft_strcmp(lt->link1, rtemp->name) == 0)
				ft_create_lvl(lt->link2, lm, i);
			else if (ft_strcmp(lt->link2, rtemp->name) == 0)
				ft_create_lvl(lt->link1, lm, i);
		}
		lt = lt->next;
	}
}
