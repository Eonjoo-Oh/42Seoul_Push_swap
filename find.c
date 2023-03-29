#include "push_swap.h"

t_node *find_close(t_list *stack_a, t_node *b_node)
{
    t_node *close;
    t_node *a_node;
    int dif;
    int temp;

    a_node = stack_a->head;
    close = NULL;
    a_node->prev->next = NULL;
    while (a_node != NULL)
    {
        if (close == NULL)
        {
            close = a_node;
            dif = make_dif(a_node, b_node);
        }
        else
            {
                temp = make_dif(a_node, b_node);
                if (temp < dif)
                    close = a_node;
            }
            a_node = a_node->next;
    }
    stack_a->head->prev->next = stack_a->head;
}

t_node *find_min_node(t_list *stack_b)
{
    t_node *min_node;
    t_node *node;
    int min_tries;
    int temp;

    b_node = stack_b->head;
    b_node->prev->next = NULL;

    while (b_node != NULL)
    {
        if (min_node == NULL)
        {
            min_node = b_node;
            min_tries = b_node->tries;
            if (min_tries == 0)
                min_tries *= -1;
        }
        temp = b_node->tries;
        if (temp < 0)
            temp *= -1;
        if (temp < min_tries)
            min_node = b_node;
        b_node = b_node->next;
    }
    stack_b->head->prev->next = stack_b->head;
    return (min_node);
}

int find_index(t_list *stack, t_node *node)
{
    t_node *first;
    int index;

    index = 0;

    first = stack->head;

    while (first != node)
    {
        index++;
        first = first->next;
    }
    return (index);
}