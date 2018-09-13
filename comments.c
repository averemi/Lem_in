/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:41:33 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:41:35 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_comment2(t_lemin *lm)
{
	if (lm->s[0] == '#' && lm->s[1] == '#' && lm->s[2] != '#'
		&& ft_strcmp(lm->s, "##start") != 0
		&& ft_strcmp(lm->s, "##end") != 0
		&& lm->ants != 0 && lm->antflag2 == 2
		&& lm->startflag2 != 1 && lm->endflag2 != 1)
	{
		ft_strdel(&lm->s);
		return (1);
	}
	return (0);
}

int		ft_comment3(t_lemin *lm)
{
	if (lm->s[0] == '#' && lm->s[1] != '#'
		&& lm->ants != 0 && lm->antflag2 == 2
		&& lm->startflag2 != 1 && lm->endflag2 != 1)
	{
		ft_strdel(&lm->s);
		return (1);
	}
	return (0);
}

int		ft_comment(t_lemin *lm)
{
	int i;

	i = 0;
	while (lm->s[i])
		i++;
	i--;
	if (i == 0)
		if (lm->s[0] == '#' && lm->s[1] == '\0'
			&& lm->ants != 0 && lm->antflag2 == 2)
		{
			ft_strdel(&lm->s);
			return (1);
		}
	if (i >= 1)
	{
		if (ft_comment3(lm))
			return (1);
	}
	if (i >= 2)
	{
		if (ft_comment2(lm))
			return (1);
	}
	return (0);
}
