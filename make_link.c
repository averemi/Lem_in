/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:36:53 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:36:54 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_check_link(t_lemin *lm, t_link lt2)
{
	t_link	*lte;
	t_room	*rt;
	int		i;

	i = 0;
	lte = lm->l;
	rt = lm->r;
	if (ft_strcmp(lt2.link1, lt2.link2) == 0)
		return (0);
	while (lte)
	{
		if (ft_check_lte(lt2, lte))
			return (0);
		lte = lte->next;
	}
	i = ft_check_startend(lt2, lm);
	while (rt)
	{
		if (ft_strcmp(lt2.link1, rt->name) == 0
			|| ft_strcmp(lt2.link2, rt->name) == 0)
			i++;
		rt = rt->next;
	}
	return (ft_count_i(i));
}

void	ft_create_link2(t_lemin *lm, t_link *lt, t_link lt2)
{
	lt = lm->l;
	while (lt)
		lt = lt->next;
	lt = (t_link *)malloc(sizeof(t_link));
	lt->link1 = lt2.link1;
	lt->link2 = lt2.link2;
	lt->linklevel1 = 0;
	lt->linklevel2 = 0;
	lt->unlinked = 0;
	lt->next = lm->l;
	lm->l = lt;
}

void	ft_check_number_links(char **s, t_lemin *lm)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (i != 2)
	{
		i = 0;
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
		s = NULL;
		ft_strdel(&lm->s);
		ft_error(lm);
	}
}

void	ft_create_link(t_lemin *lm)
{
	t_link	*lt;
	t_link	lt2;
	char	**s;

	lt = NULL;
	if (lm->antflag2 == 1)
		lm->antflag2 = 2;
	s = ft_strsplit(lm->s, '-');
	ft_check_number_links(s, lm);
	lt2.link1 = ft_strdup(s[0]);
	lt2.link2 = ft_strdup(s[1]);
	if (s)
	{
		free(s[0]);
		free(s[1]);
		free(s);
		s = NULL;
	}
	if (ft_check_link(lm, lt2))
		ft_create_link2(lm, lt, lt2);
	else
	{
		ft_strdel(&lm->s);
		ft_error(lm);
	}
}

int		ft_link(t_lemin *lm)
{
	int		i;
	char	*t;

	i = 0;
	t = lm->s;
	if (lm->startflag == 1 && lm->endflag == 1
		&& lm->startendflag == 0)
	{
		if (t[i] == '-')
			return (0);
		while (t[i] != '-' && t[i])
			i++;
		if (!t[i])
			return (0);
		i++;
		if (t[i] == '-')
			return (0);
		while (t[i] && t[i] != '-')
			i++;
		if (!t[i])
			return (1);
	}
	return (0);
}
