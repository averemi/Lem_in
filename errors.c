/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:41:42 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 13:41:45 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_error(t_lemin *lm)
{
	ft_putstr("ERROR\n");
	ft_make_free(lm);
	exit(1);
}

void	ft_error2(t_lemin *lm)
{
	ft_putstr("ERROR\n");
	if (lm->s)
		ft_strdel(&lm->s);
	ft_make_free2(lm);
	exit(1);
}
