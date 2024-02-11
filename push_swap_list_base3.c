/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_base3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:10:20 by yugao             #+#    #+#             */
/*   Updated: 2024/02/11 06:49:41 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	l_rotate_nom(t_list *l)
{
	int		tem;
	//int		ind;
	t_list	*pre;

	if (!l)
		return (FALSE);
	tem = l->num;
	//ind = l->index;
	while (l->last)
	{
		l->num = l->last->num;
		//l->index = l->last->index;
		l = l->last;
	}
	l->num = tem;
	//l->index = ind;
	return (TRUE);
}

t_bool	l_rotate_rev(t_list *l)
{
	int		tem;
	//int		ind;
	t_list	*pre;

	if (!l)
		return (FALSE);
	pre = l_grep_index (l, l_len (l) - 1);
	tem = pre->num;
	//ind = pre->index;
	while (pre->front)
	{
		pre->num = pre->front->num;
		//pre->index = pre->front->index;
		pre = pre->front;
	}
	pre->num = tem;
	//pre->index = ind;
	return (TRUE);
}

t_bool	l_push(t_list **l1, t_list **l2)
{
	t_list	*tem;

	if (!l1 || !(*l1) || !l2)
		return (FALSE);
	l_add_front (l2, l_grep_index (*l1, 0)->num);
	tem = l_grep_index (*l1, 1);
	free (*l1);
	*l1 = tem;
	l_fresh_index (*l1);
	return (TRUE);
}

t_bool	l_swap_index(t_list *l, int i1, int i2)
{
	int	tem;

	if (!l)
		return (FALSE);
	if (!l_grep_index (l, i2) || !l_grep_index (l, i1))
		return (FALSE);
	tem = l_grep_index (l, i2)->index;
	l_grep_index (l, i2)->index = l_grep_index (l, i1)->index;
	l_grep_index (l, i1)->index = tem;
	return (TRUE);
}

t_bool	l_sort(t_list *l)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	if (!l)
		return (FALSE);
	len = l_len (l);
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (l_grep_index (l, j)->num > l_grep_index (l, j + 1)->num)
				l_swap (&l, j, j + 1);
			j ++;
		}
		i ++;
	}
	return (TRUE);
}
