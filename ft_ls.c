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

void	do_ls(char *directory, int exec)
{
	DIR *dir;
	struct dirent *sd;
	t_c_list  *c_list;

	c_list = NULL;
	if (!(dir = opendir(directory)))
	{
		write(1, "ft_ls: ", 7);
		ft_putstr(directory);
		ft_putstr(" no such file or directory\n");
	}
	else
	{
		while ((sd = readdir(dir)) != NULL)
		{
			if (exec == 1)
				ls_push(&c_list, sd->d_name);
			else if (sd->d_name[0] != '.')
				ls_push(&c_list, sd->d_name);
		}
		closedir(dir);
		sort_data(&c_list);
		print_list(c_list);

	}
}	

void	check_flags(int argc, char **argv)
{
	if (argc == 1)
		do_ls(".", 0);
	if (argc >= 2)
		parse_flags(argc, argv);
}


int		main(int argc, char **argv)
{
	check_flags(argc, argv);
	return (0);
}
