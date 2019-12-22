/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:43:37 by fguzman           #+#    #+#             */
/*   Updated: 2019/12/21 21:43:42 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// C code for linked list merged sort 
#include "./ft_ls.h"
  
  
/* function prototypes 
struct Node* SortedMerge(struct Node* a, struct Node* b); 
void FrontBackSplit(struct Node* source, 
                    struct Node** frontRef, struct Node** backRef); 
 sorts the linked list by changing next pointers (not data) */




void        frontbacksplit(t_c_list *source, t_c_list **frontref, t_c_list **backref)
{
    t_c_list *fast;
    t_c_list *slow;

    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontref = source;
    *backref = slow->next;
    slow->next = NULL;
}

t_c_list    *sortedmerge(t_c_list *a, t_c_list *b)
{
    t_c_list *result;

    result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (ft_strcmp(a->dir->name, b->dir->name) < 0)
    {
        result = a;
        result->next = sortedmerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedmerge(a, b->next);
    }
    return (result);
}

void    sort_data(t_c_list **headref)
{ 
    t_c_list    *head;
    t_c_list    *a;
    t_c_list    *b;
  
    head = *headref;
    if ((head == NULL) || head->next == NULL)
        return;
    frontbacksplit(head, &a, &b);
    sort_data(&a);
    sort_data(&b);
    *headref = sortedmerge(a, b);
}