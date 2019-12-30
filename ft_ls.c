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

void	do_ls(char *directory)
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
			if (sd->d_name[0] != '.')
			ls_push(&c_list, sd->d_name);
		}
		closedir(dir);
		sort_data(&c_list);
		while(c_list != NULL)
		{
			ft_putstr(c_list->dir->name);
			write(1, "\n", 1);
			c_list = c_list->next;
		}
	}
}	

void	check_flags(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		do_ls(".");
	if (argc >= 2)
		parse_flags(argc, argv);
}


int		main(int argc, char **argv)
{
	check_flags(argc, argv);
	return (0);
}
