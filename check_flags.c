/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:23:41 by fguzman           #+#    #+#             */
/*   Updated: 2019/12/23 14:23:46 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void    get_flag(char *argv)
{
    if (ft_strcmp(argv, "-R") == 0)
        big_r_flag();
}