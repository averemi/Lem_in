/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:34:49 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:34:51 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_create_first_lvl(char *s, t_lemin *lm)
{
	t_room	*rt;
	int		i;

	i = 0;
	rt = lm->r;
	while (rt)
	{
		if (rt->lvl == 0 && (ft_strcmp(rt->name, s) == 0))
		{
			rt->lvl = lm->lvl;
			i = rt->lvl;
			ft_link_levels(lm, i, s);
			break ;
		}
		rt = rt->next;
	}
}

void	ft_make_first_level(char *s, t_lemin *lm)
{
	t_link *lt;

	lt = lm->l;
	while (lt)
	{
		if ((ft_strcmp(lt->link1, s) == 0) ||
			ft_strcmp(lt->link2, s) == 0)
		{
			if (ft_strcmp(lt->link1, s) == 0)
				ft_create_first_lvl(lt->link2, lm);
			else if (ft_strcmp(lt->link2, s) == 0)
				ft_create_first_lvl(lt->link1, lm);
		}
		lt = lt->next;
	}
}

int		ft_take_room2(t_link *ltemp, t_lemin *lm, t_room *rt, char *s)
{
	if ((ft_strcmp(ltemp->link1, s) == 0) &&
		(ft_strcmp(ltemp->link2, lm->start) != 0))
	{
		rt = lm->r;
		while (rt)
		{
			if (rt->lvl == 0 && (ft_strcmp(ltemp->link2, rt->name) == 0))
				return (1);
			rt = rt->next;
		}
	}
	return (0);
}

int		ft_take_room3(t_link *ltemp, t_lemin *lm, t_room *rt, char *s)
{
	if ((ft_strcmp(ltemp->link2, s) == 0) &&
			(ft_strcmp(ltemp->link1, lm->start) != 0))
	{
		rt = lm->r;
		while (rt)
		{
			if (rt->lvl == 0 && (ft_strcmp(ltemp->link1, rt->name) == 0))
				return (1);
			rt = rt->next;
		}
	}
	return (0);
}

int		ft_take_room(t_lemin *lm, char *s)
{
	t_link *ltemp;
	t_room *rt;

	rt = NULL;
	ltemp = lm->l;
	while (ltemp)
	{
		if ((ft_strcmp(ltemp->link1, s) == 0) ||
			(ft_strcmp(ltemp->link2, s) == 0))
		{
			if (ft_take_room2(ltemp, lm, rt, s))
				return (1);
			else if (ft_take_room3(ltemp, lm, rt, s))
				return (1);
		}
		ltemp = ltemp->next;
	}
	return (0);
}
