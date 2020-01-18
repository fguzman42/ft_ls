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

#include "ft_ls.h"


void    r_push(t_c_list **head_ref, char *str, int type)
{
    t_c_list    *new;

    new = (t_c_list *)malloc(sizeof(t_c_list));
    new->dir = (t_dir *)malloc(sizeof(t_dir));
    new->dir->name = ft_strdup(str);
    if (type == 16877)
        new->dir->type = 'a';
    else
        new->dir->type = 'n';
    new->next = (*head_ref);
    (*head_ref) = new;
}


void	init_list(t_l *list)
{
	list->byte_size = 0;
	list->group_name = NULL;
	list->links = 0;
	//list->list = NULL;
	list->owner_name = NULL;
	list->time = NULL;
}


void    ls_push(t_c_list **head_ref, char *str)
{
    t_c_list    *new;

    new = (t_c_list *)malloc(sizeof(t_c_list));
    new->dir = (t_dir *)malloc(sizeof(t_dir));
    new->dir->name = ft_strdup(str);
	new->list = malloc(sizeof(t_l));
	new->list = NULL;
	//init_list(new->list);
	//new->list->list = make_list(sd);
    new->next = (*head_ref);
    (*head_ref) = new;
}

void    r_push_dirs(t_c_list **head_ref, char *str)
{
    t_c_list    *new;

    new = (t_c_list *)malloc(sizeof(t_c_list));
    new->dir = (t_dir *)malloc(sizeof(t_dir));
    new->dir->name = ft_strdup(str);
    new->next = (*head_ref);
    (*head_ref) = new;
}


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
    if (ft_strcmp(a->dir->name, b->dir->name) <= 0)
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
    if ((head == NULL) || (head->next == NULL))
        return;
    frontbacksplit(head, &a, &b);
    sort_data(&a);
    sort_data(&b);
    *headref = sortedmerge(a, b);
}