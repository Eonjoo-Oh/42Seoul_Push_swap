#include "push_swap.h"
#include <stdio.h>
/*
void push_swap(int argc, char **argv)
{
    t_list *stack_a;
    
    if (argc == 1)
        exit(1);
    stack_a = first_stack(argv);
    if (stack_a == 0)
        exit(1);
}
*/
void push_swap(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_node *node;

    if (argc <= 2)
        exit(1);
    stack_a = first_stack(argv);
    if (stack_a == 0)
    {
        write (2, "Error\n", 6);
        exit(1);
    }
    node = stack_a->head;

    if ((check_dup(stack_a) == -1))
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    if ((check_sorted(stack_a) == -1))
        exit(1);
    if (count_node(stack_a) < 4)
    {
        sort_few(stack_a, count_node(stack_a));
        return ;
    }
    else
    {
        stack_b = (t_list *)malloc(sizeof(t_list));
        if (!stack_b)
            return (0);
        sort(stack_a, stack_b, count_node(stack_a));
    }
    // test_makestack;
    while (node->next != stack_a->head)
    {
        printf("%d\n", node->content);
        node = node->next;
    }
    printf("%d\n", node->content);
    printf("size: %d\n", count_node(stack_a));
}

int main(int argc, char ** argv)
{
    push_swap(argc, argv);
    //system ("leaks a.out");
    return (0);
}