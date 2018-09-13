/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:41:54 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:41:56 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_waystr(t_lemin *lm)
{
	while (lm->waystr)
	{
		if (lm->waystr->room)
		{
			ft_strdel(&lm->waystr->room);
			free(lm->waystr);
		}
		lm->waystr = lm->waystr->next;
	}
	free(lm->waystr);
}

void	ft_free_way(t_lemin *lm)
{
	char	**t;
	int		i;

	i = 0;
	t = lm->way;
	while (t[i])
	{
		ft_strdel(&t[i]);
		i++;
	}
	free(*t);
}

void	ft_make_free(t_lemin *lm)
{
	if (lm->str)
		ft_free_str(lm);
	if (lm->r != NULL)
		ft_free_room(lm);
	if (lm->l != NULL)
		ft_free_link(lm);
	if (lm->waystr != NULL)
		ft_free_waystr(lm);
	if (lm->way)
		ft_free_way(lm);
	if (lm->start)
		ft_strdel(&lm->start);
	if (lm->end)
		ft_strdel(&lm->end);
}

void	ft_remove_s(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_strdel(&s[i]);
		i++;
	}
	free(*s);
	s = NULL;
}

void	ft_make_free2(t_lemin *lm)
{
	if (lm->r)
		ft_free_room(lm);
	if (lm->l)
		ft_free_link(lm);
	if (lm->start)
		ft_strdel(&lm->start);
	if (lm->end)
		ft_strdel(&lm->end);
	if (lm->str)
		ft_free_str(lm);
}
