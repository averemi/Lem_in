/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:36:40 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:36:42 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_room2(char *t, int i, t_lemin *lm)
{
	if (t[i] == '-')
		i++;
	while (t[i] && t[i] != ' ')
	{
		if (!(ft_isdigit(t[i])))
			ft_error(lm);
		i++;
	}
	if (!t[i] || t[i] != ' ')
		ft_error(lm);
	if (t[i++] == ' ')
	{
		if (t[i] == '-')
			i++;
		while (t[i])
		{
			if (!(ft_isdigit(t[i])))
				ft_error(lm);
			i++;
		}
	}
	lm->str = ft_strsplit(t, ' ');
}

int		ft_room(t_lemin *lm)
{
	int		i;
	char	*t;

	i = 0;
	t = lm->s;
	if (lm->linkflag == 0 && t[i] != '#' && t[i] != 'L'
		&& !ft_link(lm))
	{
		if (t[i] == '\0')
			ft_error(lm);
		while (t[i] && t[i] != ' ')
			i++;
		if (!t[i] || t[i] != ' ')
			ft_error(lm);
		if (t[i++] == ' ')
		{
			ft_room2(t, i, lm);
			return (1);
		}
	}
	return (0);
}

void	ft_check_number(char **s, t_lemin *lm)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (i != 3)
	{
		if (lm->str)
		{
			i = 0;
			while (lm->str[i])
			{
				free(lm->str[i]);
				i++;
			}
			free(lm->str);
			lm->str = NULL;
		}
		ft_strdel(&lm->s);
		ft_error(lm);
	}
	if (lm->antflag2 == 1)
		lm->antflag2 = 2;
}

void	ft_check_start2(char **s, t_lemin *lm)
{
	if (lm->end)
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
	lm->start = ft_strdup(s[0]);
	lm->xstart = ft_atoi_lemin(s[1]);
	lm->ystart = ft_atoi_lemin(s[2]);
}

void	ft_check_start3(t_lemin *lm)
{
	if (lm->xstart > 2147483647 || lm->xstart < -2147483648
		|| lm->ystart > 2147483647 || lm->ystart < -2147483648)
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
	lm->startflag2 = 2;
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
