#include "list.h"

void    ft_swap(t_list *a, t_list *b)
{
        int     tmp = a->data;
        a->data = b->data;
        b->data = tmp;
}

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
        t_list  *tmp;

        tmp = lst;
        while (lst->next)
        {
                if ((*cmp)(lst->data, lst->next->data) == 0)
                {
                        ft_swap(lst, lst->next);
                        lst = tmp;
                }
                else
                        lst = lst->next;
        }
        lst = tmp;
        return (lst);
}