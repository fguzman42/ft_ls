/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:05:19 by fguzman           #+#    #+#             */
/*   Updated: 2019/12/31 16:05:21 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	mark_flags(t_flags *flags, char flag)
{
	if (flag == 'a')
		flags->a = 1;
	else if (flag == 'l')
		flags->l = 2;
	else if (flag == 'r')
		flags->r = 4;
	else if (flag == 'R')
		flags->ur = 8;
	else if (flag == 't')
		flags->t = 16;
}

void    handle_flags(t_flags *flag)
{
    int exec;

    exec = flag->a + flag->l + flag->t + flag->r + flag->ur;
	if (flag->a == 1)
		{
			if (exec == 1)
			//do -a
			if (exec == 3)
			//do -al
			if (exec == 5)
			//do -ar
			if (exec == 7)
			//do -alr
			if (exec == 9)
			//do -aR
			if (exec == 11)
			//do -alR
			if (exec == 13)
			//do -arR
			if (exec == 15)
			//do -alrR
			if (exec == 17)

		}

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
			handle_flags(flags);
		}
	else
		do_ls(argv);
}