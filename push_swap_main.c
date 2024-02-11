/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:36:57 by yugao             #+#    #+#             */
/*   Updated: 2024/02/11 23:43:20 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sol_pa_pb(int num_pa)
{
	int	i;

	i = 0;
	if (num_pa == 0)
		return ;
	if (num_pa < 0)
	{
		while (i < -num_pa)
		{
			printf ("pa\n");
			i ++;
		}
		return ;
	}
	while (i < num_pa)
	{
		printf ("pb\n");
		i ++;
	}
	return ;
}

// void	sol_rotate(t_list *ori, int *num_pa, int num_bit)
// {
// 	int	i;

// 	i = 1;
// 	l_print (ori);
// 	while (i < l_len (ori))
// 	{
// 		if (is_zero_bit (l_grep_index (ori, i)->num, num_bit))
// 		{
// 			if (i <= l_len (ori) / 2)
// 				l_rotate_nom (ori, num_pa);
// 			else
// 				l_rotate_rev (ori, num_pa);
// 		}
// 		i ++;
// 	}
// 	printf ("numbit : %d \n", num_bit);
// 	l_print (ori);
// }

void	solucion(t_list *ori, t_list *asis, int arc)
{
	int	num_bit;
	int	len;
	int	ispa;

	ispa = 0;
	num_bit = 0;
	while (!l_isorden (ori) || l_len (asis))
	{
		len = l_len(ori);
		while (len --)
		{
			if (is_zero_bit (l_grep_index (ori, 0)->num, num_bit))
				l_push (&ori, &asis, TRUE, &ispa);
			else
				l_rotate_nom (ori, &ispa);
			if (l_isorden (ori) && !l_len (asis))
				break ;
		}
		num_bit ++;
		while (l_len (asis))
			l_push (&asis, &ori, FALSE, &ispa);
	}
	sol_pa_pb (ispa);
}

int	main(int arc, char **argv)
{
	int		i;
	t_list	*ori; // 原始队列
	t_list	*cpy; // 原始队列的拷贝
	t_list	*asis; //辅助队列  // 注意原队列添加元素从尾部加入, asis队列加元素从头部加入.
	int		len;

	i = 1;
	ori = NULL;
	cpy = NULL;
	asis = NULL;
	if (arc == 1)
	{
		printf ("No se han introducido los numeros !!!\n");
		return (1);
	}
	while (i < arc)
	{
		if (l_add_tail (&ori, ft_atoi (argv[i])) == FALSE)
		{
			printf ("Establecimiento de list error!\n");
			return (1);
		}
		i ++;
	}
	l_copy (ori, &cpy); // 
	l_sort (cpy); // 对拷贝队列进行排序
	l_neg_to_pos (cpy, ori); // 将原来的数据用排序后的拷贝的序号替代 (全是基数, 可以用来进行基数排序)
	//l_destory (&cpy);
	//l_print (ori);
	solucion (ori, asis, arc);
	//l_print (ori);
	l_destory (&ori);
	return (0);
}
