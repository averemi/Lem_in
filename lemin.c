/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:26:00 by averemii          #+#    #+#             */
/*   Updated: 2018/03/07 20:26:04 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_create_struct2(t_lemin *lm)
{
	lm->endlink = 0;
	lm->lvl = 1;
	lm->waystr = NULL;
	lm->flagforend = 0;
	lm->antflag2 = 0;
	lm->count = 0;
}

void	ft_create_struct(t_lemin *lm)
{
	lm->s = NULL;
	lm->antflag = 0;
	lm->linkflag = 0;
	lm->startendflag = 0;
	lm->ants = 0;
	lm->x = 0;
	lm->y = 0;
	lm->startflag = 0;
	lm->startflag2 = 0;
	lm->endflag2 = 0;
	lm->endflag = 0;
	lm->str = NULL;
	lm->rflag = 0;
	lm->r = NULL;
	lm->l = NULL;
	lm->start = NULL;
	lm->end = NULL;
	lm->xstart = 0;
	lm->ystart = 0;
	lm->xend = 0;
	lm->yend = 0;
	lm->startendlink = 0;
	lm->startlink = 0;
	ft_create_struct2(lm);
}

void	ft_lemin(t_lemin *lm)
{
	ft_link_data(lm);
	ft_make_last_level(lm);
	ft_find_quickest(lm);
	ft_save_way(lm);
	ft_struct_way(lm);
	ft_display_input(lm);
	ft_rescue_ants(lm);
	ft_make_free(lm);
}

int		main(void)
{
	t_lemin lm;

	ft_create_struct(&lm);
	while (get_next_line(0, &(lm.s)) > 0)
	{
		if (ft_strcmp(lm.s, "\0") == 0)
			ft_error2(&lm);
		if (!(ft_comment(&lm)))
		{
			if (ft_ant(&lm))
				;
			else if (ft_startend(&lm))
				;
			else if (ft_room(&lm))
				ft_create_room(&lm);
			else if (ft_link(&lm))
				ft_create_link(&lm);
			else
				ft_error2(&lm);
			ft_strdel(&lm.s);
		}
	}
	ft_lemin(&lm);
	return (0);
}
