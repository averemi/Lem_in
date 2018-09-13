/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:36:34 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:36:35 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_check_start(char **s, t_room *rt1, t_lemin *lm)
{
	if (lm->startflag2 == 1)
	{
		while (rt1)
		{
			if (ft_strcmp(s[0], rt1->name) == 0)
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
			rt1 = rt1->next;
		}
		ft_check_start2(s, lm);
		ft_check_start3(lm);
		return (0);
	}
	return (1);
}

void	ft_check_end3(t_lemin *lm)
{
	if (lm->xend > 2147483647 || lm->xend < -2147483648
		|| lm->yend > 2147483647 || lm->yend < -2147483648)
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
	lm->endflag2 = 2;
	lm->startendflag = 0;
	if (lm->str)
	{
		free(lm->str[0]);
		free(lm->str[1]);
		free(lm->str[2]);
		free(lm->str);
		lm->str = NULL;
	}
}

void	ft_check_end2(char **s, t_lemin *lm)
{
	if (lm->start)
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
	lm->end = ft_strdup(s[0]);
	lm->xend = ft_atoi_lemin(s[1]);
	lm->yend = ft_atoi_lemin(s[2]);
}

int		ft_check_end(char **s, t_room *rt2, t_lemin *lm)
{
	if (lm->endflag2 == 1)
	{
		while (rt2)
		{
			if (ft_strcmp(s[0], rt2->name) == 0)
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
			rt2 = rt2->next;
		}
		ft_check_end2(s, lm);
		ft_check_end3(lm);
		return (0);
	}
	return (1);
}

void	ft_create_room3(t_lemin *lm)
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
