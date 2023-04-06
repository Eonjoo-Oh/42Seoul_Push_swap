/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonjoo <eonjoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:35:14 by eoh               #+#    #+#             */
/*   Updated: 2023/04/06 21:50:24 by eonjoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_range(long long n)
{
    if (n > 2147483647 || n < -2147483648)
        return (-1);
    return (1);
}

int check_argc(int argc)
{
    if (argc <= 2)
        return (-1);
    return (1);
}

int check_dup(t_list *stack)
{
    t_node *first_node;
    t_node *last_node;
    t_node *temp;

    first_node = stack->head;
    last_node = stack->head->prev;

    last_node->next = NULL;
    while (first_node != NULL)
    {
        temp = first_node->next;
        while (temp != NULL)
        {
            if (first_node->content == temp->content)
                return (-1);
            temp = temp->next;
        }
        first_node = first_node->next;
    }
    last_node->next = stack->head;
    return (1);
}

int check_sorted(t_list *stack)
{
    t_node *temp;

    temp = stack->head;

    if (temp->content > temp->next->content)
        return (1);
    temp = temp->next;
    while (temp->next != stack->head)
    {
       if ((temp->content < temp->prev->content) 
       || (temp->content > temp->next->content))
        return (1);
        temp = temp->next;
    }
    if (temp->content < temp->prev->content)
        return (1);
    return (-1);
}

int check_only_sign(char **argv)
{
	int	i;
	int	cnt;

	i = 1;
	while (argv[i])
	{
		cnt = 0;
		if (is_white_space(argv[i]) == -1 && is_sign(argv[i]) == -1)
			cnt++;
		if (cnt == 0)
			return (-1);
		i++;
	}
	return (1);
}

int check_arg(int argc, char **argv)
{
	if (argc < 2 || is_digit_sp(argv) == -1)
	{
		write(2, "Error\n", 6);
		return -1;
	}
	return (1);
}//argc의 갯수검사, argv에 문자가 들어있는지 검사


/*
int check_error(int argc, char **argv)
{
	t_list *stack;
	int result;

	if (argc <= 2)
		return (-1);
	if (check_only_sign(argv) == -1)
		return (-1);
	stack = first_stack(argv);
	if (!stack)
		return (0);
	if (check_dup(stack) == -1 || check_sorted(stack) == -1)
	{
		write(2, "Error\n", 6);
		result = -1;
	}
	else
		result = 1;
	free(stack);
	return (result);
}
*/

/*
int check_error(int argc, char **argv)
{
	t_list  *stack;
	int result;

	if (argc <= 2 || check_only_sign(argv) == -1)
		return (-1);
	stack = first_stack(argv);
	if (stack == 0)
	{
		write(2, "Error\n", 6);
		free(stack);
		return (-1);
	}
	if (check_dup(stack) == -1)
	{
		write(2, "Error\n", 6);
		free(stack);
		return (-1);
	}
	if (check_sorted(stack) == -1)
		free(stack);
		return (-1);
	return (1);
}
*/
