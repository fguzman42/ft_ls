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





void    big_r_flag()
{
    DIR *dir;
    struct dirent *sd;
    t_dir   *content;
    t_list  *head;
    t_list  *list;
    
    dir = opendir(".");
    head = list;
    while ((sd = readdir(dir)) != NULL)
    {
        list->dir->name = ft_strdup(sd->d_name);
        list = list->next;
    }
    head = NULL;
    closedir(dir);
}



void    get_flag(char *argv)
{
//  if (ft_strcmp(argv, "-a") == 0)
//      a_flag();
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