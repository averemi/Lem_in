/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:35:25 by averemii          #+#    #+#             */
/*   Updated: 2018/03/19 12:35:27 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_display_room_n_links(t_lemin *lm)
{
	t_room *rm;
	t_link *ln;

	rm = lm->r;
	ln = lm->l;
	while (rm)
	{
		ft_putstr(rm->name);
		ft_putstr(" ");
		ft_putnbr(rm->x);
		ft_putstr(" ");
		ft_putnbr(rm->y);
		ft_putstr("\n");
		rm = rm->next;
	}
	while (ln)
	{
		ft_putstr(ln->link1);
		ft_putstr("-");
		ft_putstr(ln->link2);
		ft_putstr("\n");
		ln = ln->next;
	}
}

void	ft_display_input(t_lemin *lm)
{
	ft_putnbr(lm->ants);
	ft_putstr("\n");
	ft_putstr("##start\n");
	ft_putstr(lm->start);
	ft_putstr(" ");
	ft_putnbr(lm->xstart);
	ft_putstr(" ");
	ft_putnbr(lm->ystart);
	ft_putstr("\n");
	ft_putstr("##end");
	ft_putstr("\n");
	ft_putstr(lm->end);
	ft_putstr(" ");
	ft_putnbr(lm->xend);
	ft_putstr(" ");
	ft_putnbr(lm->yend);
	ft_putstr("\n");
	ft_display_room_n_links(lm);
	ft_putstr("\n");
}
