/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:36:27 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:36:29 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_create_room4(t_lemin *lm, char **s)
{
	if (ft_strcmp(s[0], lm->start) == 0)
	{
		if (lm->str)
		{
			free(lm->str[0]);
			free(lm->str[1]);
			free(lm->str[2]);
			free(lm->str);
			lm->str = NULL;
		}
		ft_strdel(&lm->s);
		ft_error(lm);
	}
}

void	ft_create_room5(t_lemin *lm, char **s)
{
	if (ft_strcmp(s[0], lm->end) == 0)
	{
		if (lm->str)
		{
			free(lm->str[0]);
			free(lm->str[1]);
			free(lm->str[2]);
			free(lm->str);
			lm->str = NULL;
		}
		ft_strdel(&lm->s);
		ft_error(lm);
	}
}

void	ft_coord(t_room *rt, t_lemin *lm)
{
	if (rt->x > 2147483647 || rt->x < -2147483648
		|| rt->y > 2147483647 || rt->y < -2147483648)
	{
		if (lm->str)
		{
			free(lm->str[0]);
			free(lm->str[1]);
			free(lm->str[2]);
			free(lm->str);
			lm->str = NULL;
		}
		ft_strdel(&lm->s);
		ft_error(lm);
	}
}

void	ft_create_room2(char **s, t_lemin *lm)
{
	t_room *rt;

	rt = lm->r;
	while (rt)
	{
		if (ft_strcmp(s[0], rt->name) == 0)
			ft_create_room3(lm);
		else if (lm->start)
			ft_create_room4(lm, s);
		else if (lm->end)
			ft_create_room5(lm, s);
		rt = rt->next;
	}
	rt = (t_room *)malloc(sizeof(t_room));
	rt->name = ft_strdup(s[0]);
	rt->x = ft_atoi_lemin(s[1]);
	rt->y = ft_atoi_lemin(s[2]);
	ft_coord(rt, lm);
	rt->lvl = 0;
	rt->next = lm->r;
	lm->r = rt;
	free(lm->str[0]);
	free(lm->str[1]);
	free(lm->str[2]);
	free(lm->str);
}

int		ft_create_room(t_lemin *lm)
{
	char	**s;
	t_room	*rt1;
	t_room	*rt2;

	rt1 = lm->r;
	rt2 = lm->r;
	s = lm->str;
	ft_check_number(s, lm);
	if (lm->startflag2 == 1)
	{
		if (!ft_check_start(s, rt1, lm))
			return (0);
	}
	else if (lm->endflag2 == 1)
	{
		if (!ft_check_end(s, rt2, lm))
			return (0);
	}
	ft_create_room2(s, lm);
	lm->str = NULL;
	s = NULL;
	return (0);
}
