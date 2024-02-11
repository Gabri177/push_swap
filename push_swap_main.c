/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:36:57 by yugao             #+#    #+#             */
/*   Updated: 2024/02/11 07:25:23 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(void)
// {
	// t_list	*li;
	// t_list	*li2;

	// li = NULL;
	// li2 = NULL;
	// l_add_front (&li, 23);
	// l_add_front (&li, -9);
	// l_add_tail (&li, 28);
	// l_add_front (&li, 79);
	// l_add_tail (&li, 102);
	// l_add_tail (&li, -399);
	// l_swap(&li, 3, 4);
	// l_print (li);
	// printf ("Lenth : %d \n", l_len(li));
	//printf ("FIND : INDEX: %d, val: %d\n", l_grep_index (li, 5)->index, l_grep_index (li, 5)->num);
	// l_rotate_rev (li);
	// l_print (li);
	// l_rotate_rev (li);
	// l_rotate_rev (li);
	// l_sort (li);
	// l_print (li);
	// l_push (&li, &li2);
	// l_push (&li, &li2);
	// l_swap_index (li2, 0, 1);
	// l_print (li);
	// l_print (li2);
	// //l_destory (&li);
	// printf ("Lenth : %d \n", l_len(li));
	// printf ("Lenth : %d \n", l_len(li2));
	// if (l_isorden (li))
	// 	printf ("yes\n");
// 	return (0);
// }

int	main(int arc, char **argv)
{
	int		i;
	int		num_bit;
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
	//l_print (ori);
	l_copy (ori, &cpy); // 
	l_sort (cpy); // 对拷贝队列进行排序
	l_neg_to_pos (cpy, ori); // 将原来的数据用排序后的拷贝的序号替代 (全是基数, 可以用来进行基数排序)
	//l_print (cpy);
	//l_print (ori);
	num_bit = 0;
	while (!l_isorden (ori) || l_len (ori) != arc - 1)
	{
		i = 0;
		len = l_len(ori);
		while (i < len)
		{
			if (is_zero_bit (l_grep_index (ori, 0)->num, num_bit))
			{
				l_push (&ori, &asis);
				printf ("pa\n");
			}
			else
			{
				if (l_len (ori) != 1)
				{
					l_rotate_nom (ori);
					printf ("ra\n");
				}
			}
			i ++;
			if (l_isorden (ori) && !l_len (asis))
				break ;
		}
		num_bit ++;
		while (l_len (asis))
		{
			l_push (&asis, &ori);
			printf ("pb\n");
		}
		// printf ("=====ori=====\n");
		//l_print (ori);
		// printf ("=====ori=====\n\n");
		// printf ("=====asis=====\n");
		// l_print (asis);
		// printf ("=====asis=====\n\n");
	}
	//l_print (ori);
	l_destory (&ori);
	l_destory (&cpy);
	return (0);
}
