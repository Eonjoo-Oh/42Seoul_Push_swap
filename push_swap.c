#include "push_swap.h"
#include <stdio.h>

void new_push_swap(int argc, char **argv)
{
    t_list *stack_a;

    if (argc == 1)
        return;
    stack_a = first_stack(argv);
    if (stack_a == 0)
        write(2, "Error\n", 6);
   
}