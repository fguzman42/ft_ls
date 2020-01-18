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
		lstat(sd->d_name, &buf);
		r_push(&c_list, sd->d_name, buf.st_mode);
    }
    closedir(dir);
    sort_data(&c_list);
    while(c_list != NULL)
    {
        ft_putstr(c_list->dir->name);
        write(1, "\n", 1);
        if (c_list->dir->type == 'a')
            r_push_dirs(&dirs, c_list->dir->name);
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

    dir = opendir(".");
    c_list = NULL;
    dirs = NULL;
    while ((sd = readdir(dir)) != NULL)
    {
		lstat(sd->d_name, &buf);
		r_push(&c_list, sd->d_name, buf.st_mode);
    }
    closedir(dir);
    sort_data(&c_list);
    while(c_list != NULL)
    {
        ft_putstr(c_list->dir->name);
        write(1, "\n", 1);
        if (c_list->dir->type == 'a')
            r_push_dirs(&dirs, c_list->dir->name);
        c_list = c_list->next;
    }
    if (dirs != NULL)
    {   
        sort_data(&dirs);
        while (dirs != NULL)
        {
            printf("we will now be printing the contents of the directory: %s\n", dirs->dir->name);
            recurse(dirs->dir->name);
            dirs = dirs->next;
        }
    }
}