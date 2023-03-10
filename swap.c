#include "push_swap.h"

void sa(t_list *stack_a)
{
    t_node *first = stack_a->head;
    t_node *second = first->next;
    t_node *third = second->next;
    t_node *last = first->prev;

    stack_a->head = second;
    first->next = third;
    first->prev = second;
    second->prev = last;
    second->next = first;
    second->next = first;
    third->prev = first;
    last->prev = second;

    write (1, "sa\n", 3);
}

void sb(t_list *stack_b)
{
    t_node *first = stack_b->head;
    t_node *second = first->next;
    t_node *third = second->next;
    t_node *last = first->prev;

    stack_b->head = second;
    first->next = third;
    first->prev = second;
    second->prev = last;
    second->next = first;
    second->next = first;
    third->prev = first;
    last->prev = second;

    write (1, "sb\n", 3);
}

void ss(t_list *stack_a, t_list *stack_b)
{
    sa(stack_a);
    sb(stack_b);

    write (1, "ss\n", 3);
}