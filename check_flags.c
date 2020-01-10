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

void	print_list(t_c_list *head)
{
	while (head != NULL)
	{
		ft_putstr(head->dir->name);
		ft_putstr("\n");
		free(head->dir->name);
		free(head->dir);
		head = head->next;
	}
	free(head);
}

void	print_list_error(t_c_list *head)
{
	while (head != NULL)
	{
		ft_putstr(head->dir->name);
		ft_putstr(": is not a directory\n");
		free(head->dir->name);
		free(head->dir);
		head = head->next;
	}
	free(head);
}

void	f_sorted_and_listed(t_c_list *head, char **argv)
{
	int i;

	i = 1;
	DIR *dir;
		while (argv[i])
	{
		dir = opendir(argv[i]);
		if (dir == NULL)
			ls_push(&head, argv[i]);
		else
			closedir(dir);
		i++;
	}
	sort_data(&head);
	print_list_error(head);
}

void	d_sorted_and_listed(t_c_list *head, char **argv)
{
	int i;

	i = 1;
	DIR *dir;
		while (argv[i])
	{
		dir = opendir(argv[i]);
		if (dir != NULL)
		{
			ls_push(&head, argv[i]);
			closedir(dir);
		}
		i++;
	}
	sort_data(&head);
	while (head != NULL)
	{
		ft_putstr(head->dir->name);
		ft_putstr(":\n");
		do_ls(head->dir->name, 0);
		if (head->next != NULL)
			ft_putstr("\n");
		head = head->next;
	}
}

void	list_args(char **argv)
{
	int i;
	t_c_list *head;

	head = NULL;
	i = 1;
	f_sorted_and_listed(head, argv);
	d_sorted_and_listed(head, argv);
}


void	parse_flags(int argc, char **argv)
{
	int i;
	t_flags flags;
	t_c_list	*head;

	i = 1;
	head = NULL;
	init_flags(&flags);
	if (argc == 2)
		find_flags(&flags, argv[1]);
	else if (argc > 2)
	{
			list_args(argv);
		/*if (argv[1][0] == '-')
			function_that_checks_for_flags(flags);
		else
			list_args(argv);*/
	}
}  

void	get_flag(char *argv)
{
	if (ft_strcmp(argv, "-R") == 0)
		big_r_flag();
}