/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 03:21:17 by fguzman           #+#    #+#             */
/*   Updated: 2019/12/23 03:21:19 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

    dir = opendir("/Library");
    c_list = NULL;
    dirs = NULL;
    while ((sd = readdir(dir)) != NULL)
    {
        if (sd->d_name[0] != '.')
        {
            lstat(sd->d_name, &buf);
            printf("%s %d\n", sd->d_name, buf.st_mode);
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