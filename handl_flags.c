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
		flags->l = 1;
	else if (flag == 'r')
		flags->r = 1;
	else if (flag == 'R')
		flags->ur = 1;
	else if (flag == 't')
		flags->t = 1;
}

/*
void    handle_flags(t_flags *flag)
{
	//
//	    int exec;

    //exec = flag->a + flag->l + flag->t + flag->r + flag->ur;
	if (flag->a == 1)
		{
			if (exec == 1)
				do_ls(".", exec);
			if (exec == 3)
			//do -al
				do_ls(".", 3);
		}
			
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
			//do -at
			if (exec == 19)
			//do -alt
			if (exec == 21)
			//do -art
			if (exec == 23)
			//do -alrt
			if (exec == 25)
			//do -aRt
			if (exec == 27)
			//do -alRt
			if (exec == 29)
			//do -arRt
			if (exec == 31)
			//do -alrRt
		}
		if (flag->l == 1)
		{
			if (exec == 2)
			//do -l
			if (exec == 4)
			//do -r
			if (exec == 6)
			//do -lr
			if (exec == 8)
			//do -R
			if (exec == 10)
			//do -lR
			if (exec == 12)
			//do -rR
			if (exec == 14)
			//do -lrR
			if (exec == 16)	
			//do -t
			if (exec == 18)
			//do -lt
			if (exec == 20)
			//do -rt
			if (exec == 22)
			//do -lrt
			if (exec == 24)
			//do -Rt
			if (exec == 26)
			//do -lRt
			if (exec == 28)
			//do -rRt
			if (exec == 30)
			//do -lrRt
		}


}
*/



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
			if (flags->l == 1)
				do_l(".");
			//handle_flags(flags);
		}
	else
		do_ls(argv);
}