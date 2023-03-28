#include "push_swap.h"

void push_to_b(t_list *stack_a, t_list *stack_b, int size)
{
    while (size > 3)
    {
        pb(stack_a, stack_b);
        size--;
    }
    sort_few(stack_a, 3);
}

int find_index(t_list *stack, t_node *node)
{
    t_node *first;
    int index;

    index = 1;

    first = stack->head;

    while (first != node)
    {
        index++;
        first = first->next;
    }
    return (index);
}

void count_tries(t_list *stack_a, t_list *stack_b)
{
    t_node *b_node;
    t_node *a_node;
    int index;
    int count;

    b_node = stack_b->head;

    b_node->prev->next = NULL;
    while (b_node != NULL)
    {
        a_node = stack_a->head;
        count = 0;
        index = find_index(stack_b, b_node);
        if (index <= count_node(stack_b) / 2 + 1)
            count += (index - 1);
        else
            count += count_node(stack_b) - index + 1;
        // pb의 가장 위에 올리는것까지 세어주었다. 옆으로 넘기기 위한 작업을 해야함
        while (1)
        {
            if (a_node == stack_a->head)
            {
                if (a_node->content > b_node->content)
                {
                    count++;
                    break;
                }
            } // 맨 앞에 들어올 때
            else if (a_node == stack_a->head->prev && a_node->content < b_node->content)
            {
                count += 2;
                break;
            } // 제일 끝에 들어올 때
            else
            {
                if ((a_node->content > b_node->content) && (a_node->prev->content < b_node->content))
                {
                    index = find_index(stack_a, a_node);
                    if (index <= count_node(stack_a) / 2 + 1)
                        count += (index - 1) * 2 + 1;
                    else
                        count += 2 * (count_node(stack_a) - index) + 4;
                    break;
                }
            }
            // 중간에 들어올 때
            a_node = a_node->next;
        }
        b_node->tries = count;

        if (count == 1)
            break; // count가 1이면 볼것도 없기때문에 그냥 종료함
        b_node = b_node->next;
    }
    stack_b->head->prev->next = stack_b->head;
}

t_node *find_min_tries(t_list *stack_b)
{
    t_node *b_node;
    t_node *min_node;

    b_node = stack_b->head;
    min_node = b_node;

    b_node->prev->next = NULL;

    while (b_node != NULL)
    {
        if (b_node->tries == 1)
        {
            min_node = b_node;
            break;
        }
        if (min_node->tries > b_node ->tries)
            min_node = b_node;
        b_node = b_node->next;
    }
    stack_b->head->prev->next = stack_b->head;
    return (min_node);
}

void put_last(t_list *stack_a, t_list *stack_b)
{
    pa(stack_a, stack_b);
    ra(stack_a);
}

int sort_more(t_list *stack_a, t_list *stack_b)
{
    int result;
    t_node *target;
    t_node *temp;

    target = NULL;
    temp = stack_b->head;
    stack_b->head->prev->next = NULL;

    while (temp != NULL)
    {
        if (temp->content < stack_a->head && temp->content > target->content)
            target = temp;
        temp = temp->next;
    }
    if (target = NULL)
    {
        stack_b->head->prev->next = stack_b->head;
        return (-1);
    }
    else
    {
        
    }
}

void sort_do(t_list *stack_a, t_list *stack_b, t_node *node)
{
    int index;
    int t_index;
    t_node *a_node;
    t_node *b_node;
    t_node *min_node;

    a_node = stack_a->head;
    b_node = stack_b->head;
    while (b_node->next != b_node)
    {
        if (b_node == node)
            break;
        b_node = b_node->next;
    }
    min_node = b_node;
    //min_node 찾기

    if (min_node->tries == 1)
    {
        pa(stack_a, stack_b);
        return ;
    }//min_node의 tries가 1일 경우 따로 빼줌->이게 굳이 필요할까?
    index = find_index(stack_b, min_node);
    if (index <= count_node(stack_b) / 2 + 1)
    {
        while (stack_b->head != min_node)
            rb(stack_b);
    }
    else
    {
        while (stack_b->head != min_node)
            rrb(stack_b);
    }
    //min_node를 stack_b의 가장 위에 올려줌

    while (1)
    {
        if (a_node == stack_a->head && a_node->content > min_node->content)
        {
            pa(stack_a, stack_b);
            return ;
        } // stack_a의 제일 위에 올라올 때
        else if (a_node->next == stack_a->head && a_node->content < min_node->content)
        {
            put_last(stack_a, stack_b);
            return;
        }// stack_a의 제일 마지막에 들어올 때
        else
        {
            if (min_node->content > a_node->content && min_node->content < a_node->next->content)
            {
                index = find_index(stack_a, a_node);
                t_index = index;
                if (index < count_node(stack_a) / 2 + 1)
                {
                    while (t_index-- > 0)
                        ra(stack_a);
                    pa(stack_a, stack_b);
                    while (sort_more(stack_a, stack_b) != 1)
                        sort_more(stack_a, stack_b);
                    while (t_index++ < index - 1)
                        rra(stack_a);
                    return;
                }
                else
                {
                    while (t_index-- > 1)
                        rra(stack_a);
                    pa(stack_a, stack_b);
                    while (sort_more(stack_a, stack_b) != 1)
                        sort_more(stack_a, stack_b)
                    while (t_index++ < index)
                        ra(stack_a);
                    return;
                }
            }
        } // 중간에 낄 때
        a_node = a_node->next;
    }
}

void sort(t_list *stack_a, t_list *stack_b, int size)
{
    t_node *min_node;
    
    push_to_b(stack_a, stack_b, size);
    while (stack_b->head != NULL)
    {
        count_tries(stack_a, stack_b);
        min_node = find_min_tries(stack_b);
        sort_do(stack_a, stack_b, min_node);
    }
}