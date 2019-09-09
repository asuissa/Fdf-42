/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:45:22 by asuissa           #+#    #+#             */
/*   Updated: 2018/03/07 21:52:10 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_key(int keycode, t_param *p)
{
	p->alpha += keycode == ROT1 ? 0.1 : 0;
	p->alpha -= keycode == ROT2 ? 0.1 : 0;
	p->key += keycode == PAGEUP && p->key < INT_MAX ? 1 : 0;
	p->key -= keycode == PAGEDOWN && p->key > 5 ? 1 : 0;
	if (keycode == 0 && p->key > 5)
		p->justify -= 2;
	if (keycode == 2 && p->key > 5)
		p->justify += 2;
	p->col0 += keycode == C ? 1 : 0;
	p->width -= keycode == W ? 3 : 0;
	p->width += keycode == S ? 3 : 0;
	p->height += keycode == PLUS ? 1 : 0;
	p->height -= keycode == MINUS ? 1 : 0;
	if (keycode == ESC)
		exit(0);
	mlx_clear_window(p->mlx, p->win);
	create_image(p->tab, p);
	if (keycode == DEL)
		mlx_clear_window(p->mlx, p->win);
	return (keycode);
}
