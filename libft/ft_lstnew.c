/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:29:58 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/02 04:07:46 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*tmp_content;
	size_t	tmp_size;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		tmp_content = ft_memalloc(content_size + 1);
		tmp_size = content_size;
		ft_memcpy(tmp_content, content, content_size);
		new->content = tmp_content;
		new->content_size = tmp_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
