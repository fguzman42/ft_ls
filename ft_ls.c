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



/*void   sort_data(t_c_list *head)
{
    t_c_list *elem;
    char *tmp;
    int i;

    i = 0;
    elem = head;
    tmp = NULL;
    while (elem->next != NULL)
    {
        if (elem->next->dir != NULL)
        {
            if (ft_strcmp(elem->dir->name, elem->next->dir->name) > 0)
            {
                tmp = elem->dir->name;
                elem->dir->name = elem->next->dir->name;
                elem->next->dir->name = tmp;
				elem = head;
            }
        }
        elem = elem->next;
        i++;
    }
}*/
void    push(t_c_list **head_ref, char *str, int type)
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


void    push_dirs(t_c_list **head_ref, char *str)
{
    t_c_list    *new;

    new = (t_c_list *)malloc(sizeof(t_c_list));
    new->dir = (t_dir *)malloc(sizeof(t_dir));
    new->dir->name = ft_strdup(str);
    new->next = (*head_ref);
    (*head_ref) = new;
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


void    recurse(char *directory)
{
    DIR *dir;
    struct dirent *sd;
    struct stat buf;
    t_c_list  *c_list;
    t_c_list  *dirs;
    
    dir = opendir(directory);
    c_list = NULL;
    dirs = NULL;
    while ((sd = readdir(dir)) != NULL)
    {
        if (sd->d_name[0] != '.')
        {
            stat(sd->d_name, &buf);
            push(&c_list, sd->d_name, buf.st_mode);
        }
    }
    closedir(dir);
    sort_data(&c_list);
    while(c_list != NULL)
    {
        ft_putstr(c_list->dir->name);
        write(1, "\n", 1);
        if (c_list->dir->type == 'a')
            push_dirs(&dirs, c_list->dir->name);
        free(c_list->dir->name);
        free(c_list->dir);
        c_list = c_list->next;
    }
    if (dirs != NULL)
    {
        while (dirs->next)
        {
            recurse(dirs->dir->name);
            dirs = dirs->next;
        }
    }
}



void    big_r_flag()
{
    DIR *dir;
    struct dirent *sd;
    struct stat buf;
    t_c_list  *c_list;
    t_c_list  *dirs;
    
    dir = opendir("/");
    c_list = NULL;
    dirs = NULL;
    while ((sd = readdir(dir)) != NULL)
    {
        if (sd->d_name[0] != '.')
        {
            lstat(sd->d_name, &buf);
            printf("%s %o\n", sd->d_name, buf.st_mode);
            push(&c_list, sd->d_name, buf.st_mode);
        }
    }
    closedir(dir);
    sort_data(&c_list);
    while(c_list != NULL)
    {
        ft_putstr(c_list->dir->name);
        write(1, "\n", 1);
        printf("the name of the dir is %c\n", c_list->dir->type);
        if (c_list->dir->type == 'a')
            push_dirs(&dirs, c_list->dir->name);
        c_list = c_list->next;
    }
    if (dirs != NULL)
    {   
        sort_data(&dirs);
        while (dirs != NULL)
        {
            printf("the name of the dir is %s\n", dirs->dir->name);
            recurse(dirs->dir->name);
            dirs = dirs->next;
        }
    }
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