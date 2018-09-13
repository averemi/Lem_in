/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:41:13 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:41:15 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

long int	ft_atoi_lemin(const char *str)
{
	long int	result;
	int			sign;
	size_t		i;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= 48
			&& str[i + 1] <= '9'))
		i++;
	while (str[i] >= 48 && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return ((result * sign));
}

void		ft_check_ants_num(t_lemin *lm)
{
	if (lm->ants == 0 || lm->ants > 2147483647)
	{
		ft_strdel(&lm->s);
		ft_error(lm);
	}
	lm->antflag = 1;
	lm->antflag2 = 1;
}

int			ft_ant(t_lemin *lm)
{
	int i;

	i = 0;
	if (lm->antflag == 1)
		return (0);
	if (lm->antflag == 0)
	{
		while (lm->s[i])
		{
			if (!(ft_isdigit(lm->s[i])))
			{
				ft_strdel(&lm->s);
				ft_error(lm);
			}
			i++;
		}
		lm->ants = ft_atoi_lemin(lm->s);
		ft_check_ants_num(lm);
		ft_strdel(&lm->s);
	}
	return (1);
}
