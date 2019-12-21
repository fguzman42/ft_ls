/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:22:27 by fguzman           #+#    #+#             */
/*   Updated: 2019/12/17 10:22:33 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"
#include <stdio.h>

void    no_flag(char *directory)
{
    DIR *dir;
    struct dirent *sd;

    if (directory != NULL)
        dir = opendir(directory);
    else
        dir = opendir(".");
    if (dir == NULL)
        ft_puterror("bad file man!", 1);
    while ((sd = readdir(dir)) != NULL)
    {
        ft_putstr(sd->d_name);
        write(1, "\n", 1);
    }
    free (directory);
    closedir(dir);
}


void    a_flag()
{
    DIR *dir;
    struct dirent *sd;

    dir = opendir(".");
    if (dir == NULL)
        ft_puterror("bad file man!", 1);
    while ((sd = readdir(dir)) != NULL)
    {
        ft_putstr(sd->d_name);
        write(1, "\n", 1);
    }
    closedir(dir);
}


/*
this is my prototype for my recursive function for -R

    -R()
    {
        sort and print(list)
        {
            return (list of directories)
        }
        if (directories)
            -R
    }

*/

void   sort_data(t_c_list *head)
{
    t_c_list *elem;
    char *tmp;
    int i;

    i = 0;
    elem = head;
    tmp = NULL;
    while (elem->next != NULL)
    {
        printf("%d = %s\n", i, elem->dir->name);
        if (elem->next->dir != NULL)
        {
<<<<<<< HEAD
            if (ft_strcmp(elem->dir->name, elem->next->dir->name) > 0)
=======
            if (elem->dir->name[0] == elem->next->dir->name[0])
                {
                    if (ft_strcmp(elem->dir->name, elem->next->dir->name) > 0)
                    {
                        tmp = elem->dir->name;
                        elem->dir->name = elem->next->dir->name;
                        elem->next->dir->name = tmp;
						elem = head;
                    }
                }
            else if (elem->dir->name[0] > elem->next->dir->name[0])
>>>>>>> 3f2a239517f7ec6d74dd7a3285063c25f81afc06
            {
                tmp = elem->dir->name;
                elem->dir->name = elem->next->dir->name;
                elem->next->dir->name = tmp;
				elem = head;
<<<<<<< HEAD
                printf("hello %s\n", elem->dir->name);
=======
>>>>>>> 3f2a239517f7ec6d74dd7a3285063c25f81afc06
            }
        }
        elem = elem->next;
        i++;
    }
<<<<<<< HEAD

=======
>>>>>>> 3f2a239517f7ec6d74dd7a3285063c25f81afc06
       while (head->next != NULL)
    {
        printf("%s\n", head->dir->name);
        free(head->dir->name);
        free(head->dir);
        free(head);
        head = head->next;
    }
    free(head);
<<<<<<< HEAD
    
=======
>>>>>>> 3f2a239517f7ec6d74dd7a3285063c25f81afc06
}


void    big_r_flag()
{
    DIR *dir;
    struct dirent *sd;
    t_c_list  *head;
    t_c_list  *c_list;
    
    dir = opendir(".");
    c_list = malloc(sizeof(t_c_list *));
    head = c_list;
    while ((sd = readdir(dir)) != NULL)
    {
        if (sd->d_name[0] != '.')
        {
            c_list->dir = malloc(sizeof(t_dir));
            c_list->dir->name = ft_strdup(sd->d_name);
            c_list->next = malloc(sizeof(t_c_list *)); 
            c_list = c_list->next;
            c_list->dir = NULL;
        }
    }
    c_list = NULL;
    sort_data(head);



/*
    //this while loop iterates through the linked list and displays its contents
    //used for reference.
    printf("this is the unsorted below\n\n");
    while (head->next != NULL)
    {
        printf("directory ./%s\n", head->dir->name);
        free(head->dir->name);
        free(head->dir);
        free(head);
        head = head->next;
    }
    free(head);
*/
    closedir(dir);
}



void    get_flag(char *argv)
{
    if (ft_strcmp(argv, "-R") == 0)
        big_r_flag();
}


int main(int argc, char **argv)
{
    if (argc == 2)
        get_flag(argv[1]);
    return (0);
}

/*
int main(int argc, char **argv)
{
    (void)argc;
    DIR *dir;
    struct dirent *sd;

    dir = opendir(argv[1]);
    if(dir == NULL)
    {
        printf("error opening directory\n");
        exit (1);
    }
    while((sd = readdir(dir)) != NULL)
        printf(">> %s\n", sd->d_name);
    closedir(dir);
}
*/