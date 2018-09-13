/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:42:15 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:42:17 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_startend2(t_lemin *lm)
{
	if (lm->antflag2 == 1)
		lm->antflag2 = 2;
	if (lm->linkflag == 1)
	{
		ft_strdel(&lm->s);
		ft_error(lm);
	}
	lm->startendflag = 1;
}

void	ft_startend3(t_lemin *lm)
{
	if (ft_strcmp(lm->s, "##start") == 0)
	{
		if (lm->startflag == 1)
		{
			ft_strdel(&lm->s);
			ft_error(lm);
		}
		lm->startflag = 1;
		lm->startflag2 = 1;
	}
	else if (ft_strcmp(lm->s, "##end") == 0)
	{
		if (lm->endflag == 1)
		{
			ft_strdel(&lm->s);
			ft_error(lm);
		}
		lm->endflag = 1;
		lm->endflag2 = 1;
	}
}

int		ft_startend(t_lemin *lm)
{
	if (lm->startendflag == 0 && (ft_strcmp(lm->s, "##start") == 0
		|| ft_strcmp(lm->s, "##end") == 0))
	{
		ft_startend2(lm);
		ft_startend3(lm);
		return (1);
	}
	return (0);
}

int		ft_check_startend(t_link lt2, t_lemin *lm)
{
	if ((ft_strcmp(lt2.link1, lm->start) == 0 &&
		ft_strcmp(lt2.link2, lm->end) == 0) ||
		(ft_strcmp(lt2.link2, lm->start) == 0 &&
			ft_strcmp(lt2.link1, lm->end) == 0))
	{
		lm->startendlink = 1;
		lm->startendlink2 = 1;
		return (2);
	}
	else if ((ft_strcmp(lt2.link2, lm->start) == 0) ||
		(ft_strcmp(lt2.link1, lm->start) == 0))
	{
		lm->startlink = 1;
		return (1);
	}
	else if ((ft_strcmp(lt2.link2, lm->end) == 0) ||
		(ft_strcmp(lt2.link1, lm->end) == 0))
	{
		lm->endlink = 1;
		return (1);
	}
	return (0);
}
