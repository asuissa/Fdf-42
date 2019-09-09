/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:45:48 by asuissa           #+#    #+#             */
/*   Updated: 2018/03/07 21:51:38 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		map_dimension(char *file, t_param *p)
{
	int i;
	int nb;

	i = -1;
	p->col = 0;
	nb = 0;
	while (file[++i])
	{
		p->row = 0;
		while (file[i] != '\n')
		{
			while (file[i] == ' ')
				i++;
			if ((file[i] >= '0' && file[i] <= '9') || file[i] == '-')
				p->row++;
			while (file[i] != ' ' && file[i] != '\n' && file[i] != '\0')
				i++;
		}
		if (nb != p->row && p->col != 0)
			return (-1);
		nb = p->row;
		p->col++;
	}
	p->row = nb;
	return (0);
}
