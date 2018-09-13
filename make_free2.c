/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_free2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:42:05 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:42:07 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_room(t_lemin *lm)
{
	while (lm->r)
	{
		if (lm->r->name)
		{
			ft_strdel(&lm->r->name);
			free(lm->r);
		}
		lm->r = lm->r->next;
	}
	free(lm->r);
}

void	ft_free_link(t_lemin *lm)
{
	while (lm->l)
	{
		if (lm->l->link1)
		{
			ft_strdel(&lm->l->link1);
		}
		if (lm->l->link2)
		{
			ft_strdel(&lm->l->link2);
		}
		free(lm->l);
		lm->l = lm->l->next;
	}
	free(lm->l);
}

void	ft_free_str(t_lemin *lm)
{
	char	**t;
	int		i;

	t = lm->str;
	i = 0;
	while (t[i])
	{
		ft_strdel(&t[i]);
		i++;
	}
	free(*t);
	lm->str = NULL;
}
