// Nao esquecer da Header

#include "push_swap.h"

void    fill_index(t_list **stack)
{
    t_list  *head;
    t_list  *current;
    t_list  *temp;
    int     index;

    head = *stack;
    current = *stack;
    temp = head;

    while (current)
    {
        index = 0;
        while (head)
        {
            if (current->data > head->data)
                index++;
            head = head->next;
        }
        current->index = index;
        current = current->next;
        head = temp;
    }
}