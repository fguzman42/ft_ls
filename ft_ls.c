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

void    a_flag(char *directory)
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

void    get_flag(char *argv, char *directory)
{

    if (ft_strcmp(argv, "-a") == 0)
        a_flag(directory);
}


int main(int argc, char **argv)
{
    DIR *dir;
    char *d;
    char p[50];

    p[0] = argv[argc - 1][0];
    d = NULL;
    dir = opendir(argv[argc - 1]);
    if (dir == NULL && (ft_strcmp(p, "-") == 0))
        ft_puterror("ft_ls: -a: no such file or directory", 0);
    else if (dir != NULL)
        d = ft_strdup(argv[argc - 1]);
    get_flag(argv[1], d);
    closedir(dir);
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