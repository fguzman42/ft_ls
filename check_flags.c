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


void	init_flags(t_flags *flags)
{
	flags->a = 0;
	flags->l = 0;
	flags->r = 0;
	flags->ur = 0;
	flags->t = 0;
}

void	mark_flags(t_flags *flags, char flag)
{
	if (flag == 'l')
		flags->l = 1;
	else if (flag == 'a')
		flags->a = 1;
	else if (flag == 'r')
		flags->r = 1;
	else if (flag == 'R')
		flags->ur = 1;
	else if (flag == 't')
		flags->t = 1;
}

void	find_flags(t_flags *flags, char *argv)
{
	int i;

	i = 0;
	if (argv[i] == '-')
		{
			i++;
			while (argv[i])
			{
				if (argv[i] == 'l' || argv[i] == 'a' ||
				argv[i] == 'r' || argv[i] == 'R' || argv[i] == 't')
					mark_flags(flags, argv[i]);
				else
					ft_puterror("no flag found\n", 0);
				i++;
			}
			//handle_flags(&flags);
		}
		else
			do_ls(argv);
}

void	parse_flags(int argc, char **argv)
{
	int i;
	t_flags flags;

	i = 1;

	init_flags(&flags);
	if (argc == 2)
		find_flags(&flags, argv[1]);
	else if (argc > 2)
	{
		if (argv[1][0] != '-')
		{
			while (argv[i])
			{
				if (argv[i][0] == '-')
					do_ls(argv[i]);
				i++;
			}
		}

	}

}  

void	get_flag(char *argv)
{
	if (ft_strcmp(argv, "-R") == 0)
		big_r_flag();
}