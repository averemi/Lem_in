/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:32:29 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:32:40 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_find_quickest3(t_link *ltemp2, t_link *ltemp, t_lemin *lm)
{
	if ((ft_strcmp(ltemp2->link1, lm->end) == 0 &&
		ltemp2->linklevel2 > ltemp->linklevel1
		&& ft_strcmp(lm->start, ltemp2->link2) != 0 &&
		ltemp->linklevel1 != 0) ||
		(ft_strcmp(ltemp2->link1, lm->end) == 0 &&
		ltemp2->linklevel2 > ltemp->linklevel1
		&& ft_strcmp(lm->start, ltemp2->link2) == 0) ||
		(ft_strcmp(ltemp2->link2, lm->end) == 0 &&
		ltemp2->linklevel1 > ltemp->linklevel1
		&& ft_strcmp(lm->start, ltemp2->link1) != 0 &&
		ltemp->linklevel1 != 0) ||
		(ft_strcmp(ltemp2->link2, lm->end) == 0 &&
		ltemp2->linklevel1 > ltemp->linklevel1
		&& ft_strcmp(lm->start, ltemp2->link1) == 0))
		return (1);
	return (0);
}

void	ft_find_quickest0(t_link *ltemp2, t_link *ltemp, t_lemin *lm)
{
	ltemp2 = lm->l;
	while (ltemp2)
	{
		if ((ft_strcmp(ltemp2->link1, lm->end) == 0 &&
		ltemp2->linklevel2 > ltemp->linklevel2 &&
		ft_strcmp(lm->start, ltemp2->link2) != 0 &&
		ltemp->linklevel2 != 0) ||
		(ft_strcmp(ltemp2->link1, lm->end) == 0 &&
		ltemp2->linklevel2 > ltemp->linklevel2
		&& ft_strcmp(lm->start, ltemp2->link2) == 0) ||
		(ft_strcmp(ltemp2->link2, lm->end) == 0 &&
		ltemp2->linklevel1 > ltemp->linklevel2
		&& ft_strcmp(lm->start, ltemp2->link1) != 0 &&
		ltemp->linklevel2 != 0) ||
		(ft_strcmp(ltemp2->link2, lm->end) == 0 &&
		ltemp2->linklevel1 > ltemp->linklevel2
		&& ft_strcmp(lm->start, ltemp2->link1) == 0))
			ltemp2->unlinked = 1;
		ltemp2 = ltemp2->next;
	}
}

void	ft_find_quickest(t_lemin *lm)
{
	t_link *ltemp;
	t_link *ltemp2;

	ltemp = lm->l;
	while (ltemp)
	{
		if (ft_strcmp(lm->end, ltemp->link1) == 0)
			ft_find_quickest0(ltemp2, ltemp, lm);
		else if (ft_strcmp(lm->end, ltemp->link2) == 0)
		{
			ltemp2 = lm->l;
			while (ltemp2)
			{
				if (ft_find_quickest3(ltemp2, ltemp, lm))
					ltemp2->unlinked = 1;
				ltemp2 = ltemp2->next;
			}
		}
		ltemp = ltemp->next;
	}
}

char	*ft_find_path(int lvl, char *link, t_lemin *lm)
{
	t_link *lt;

	lvl--;
	lt = lm->l;
	while (lt)
	{
		if (ft_strcmp(link, lt->link1) == 0 && lt->linklevel2 == lvl
			&& lt->unlinked == 0)
			return (lt->link2);
		else if (ft_strcmp(link, lt->link2) == 0 &&
			lt->linklevel1 == lvl && lt->unlinked == 0)
			return (lt->link1);
		lt = lt->next;
	}
	return (NULL);
}

void	ft_correct_way(int lvl, char *link, t_lemin *lm)
{
	int		i;
	int		z;
	char	*s;
	char	**t;

	s = link;
	i = 0;
	z = lvl;
	lm->way = (char **)malloc(sizeof(char *) * (lvl + 3));
	t = lm->way;
	if (link)
	{
		i = lvl - 1;
		while (lvl > 0 && s)
		{
			s = ft_find_path(lvl, s, lm);
			t[i] = ft_strdup(s);
			lvl--;
			i--;
		}
		t[z] = ft_strdup(link);
		t[z + 1] = ft_strdup(lm->end);
		t[z + 2] = NULL;
	}
}
