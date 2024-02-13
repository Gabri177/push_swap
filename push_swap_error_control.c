#include "push_swap.h"

void	arc_check(int arc, t_list **ori, t_list **cpy, t_list **asis)
{
	if (arc == 1)
	{
		printf ("No se han introducido los numeros !!!\n");
		exit (EXIT_FAILURE);
	}
	*ori = NULL;
	*cpy = NULL;
	*asis = NULL;
}

t_bool	num_check(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9')&& *str != '-')
			return (FALSE);
		str ++;
	}
	return (TRUE);
}

t_bool	rept_check(t_list *l)
{
	t_list	*head;

	head = l;
	if (!l)
	{
		l_destory (&l);
		return (FALSE);
	}
	while (l->last)
	{
		if (l->num == l->last->num)
		{
			l_destory (&head);
			return (FALSE);
		}
		l = l->last;
	}
	return (TRUE);
}

void	err_control(t_list **l, t_err type)
{
	if (type == ERR_READ)
		printf ("Establecimiento de list error!\n");
	else if (type == ERR_LETRA)
		printf ("Hay letra mezclada dentro de los argumentos!\n");
	else if (type == ERR_REPETIR)
		printf ("ERROR :Hay numeros repetidos!\n");
	if (l_len (*l) != 0)
		l_destory (l);
	exit (EXIT_FAILURE);
}
