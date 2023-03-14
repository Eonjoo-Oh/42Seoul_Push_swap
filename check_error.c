#include "push_swap.h"

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

int check_error(int argc, char **argv)
{
    t_list  *stack;
    
    if (argc <= 2)
        return (-1);
    stack = first_stack(argv);
    if (stack == 0)
    {
        write(2, "Error\n", 6);
        return (-1);
    }
    if (check_dup(stack) == -1)
    {
        write(2, "Error\n", 6);
        return (-1);
    }
    if (check_sorted(stack) == -1)
        return (-1);
    return (1);
}