/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:48:07 by eoh               #+#    #+#             */
/*   Updated: 2023/04/10 01:12:53 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *arr, int size)
{
	int	i;
	int	temp;

	while (size > 1)
	{
		i = 0;
		while (i + 1 < size)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			i++;
		}
		size--;
	}
}

int	find_to_push(t_list *stack_a, int pivot)
{
	t_node	*node;
	int		result;

	result = -1;
	node = stack_a->head;
	node->prev->next = NULL;
	while (node != NULL)
	{
		if (node->content < pivot)
		{
			result = 1;
			break ;
		}
		node = node->next;
	}
	stack_a->head->prev->next = stack_a->head;
	return (result);
}

void	do_push_to_b(int st, int nd, t_list *stack_a, t_list *stack_b)
{
	t_node	*node;

	node = stack_a->head;
	while (count_node(stack_a) > 3 && find_to_push(stack_a, nd) == 1)
	{
		if (node->content <= nd)
		{
			node = node->next;
			pb(stack_a, stack_b);
			if (stack_b->head->content <= st)
				rb(stack_b);
		}
		else
		{
			ra(stack_a);
			node = node->next;
		}
	}
	while (count_node(stack_a) > 3)
	{
		pb(stack_a, stack_b);
	}
}

void	push_to_b(t_list *stack_a, t_list *stack_b)
{
	int		*arr;
	int		first_pivot;
	int		second_pivot;

	arr = make_arr(stack_a, count_node(stack_a));
	sort_arr(arr, count_node(stack_a));
	first_pivot = arr[count_node(stack_a) / 3];
	second_pivot = arr[count_node(stack_a) / 3 * 2];
	do_push_to_b(first_pivot, second_pivot, stack_a, stack_b);
	free(arr);
}
