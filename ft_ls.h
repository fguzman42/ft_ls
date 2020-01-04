/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:22:39 by fguzman           #+#    #+#             */
/*   Updated: 2019/12/17 10:22:44 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
To get started
Here are some ideas for programs whose realization will help you make your project.

List a directory
• Write a program that uses the opendir, readdir and closedir functions to
open a directory and list the names of what it contains on the console.

• Example:
$> mkdir -p toto / tyty
$> touch toto / {tata, titi, tutu}
$> ./ ft_list_dir toto
auntie
titi
tutu
tyty
$


II.2 Obtaining information about a file

• Write a program that takes a file as a parameter and uses, among other things, the
stat function to obtain information about this file and display it on the screen.

• Example:
$> ./ ft_inspect_file un_fichier_de_ouf
Name: un_fichier_de_ouf
Type: File
Modes: rwxr-xr-x
Number of links: 1
Owner: zaz
Group: staff
Size: 2142 bytes
Date of last modification: Sep 17 23:42
$>


• You will have to use several functions, given at the beginning of this document,
in order to interpret the information returned by stat!

*/
#ifndef FT_LS_H
# define FT_LS_H

#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "./libft/libft.h"
# define L_FLAG 1
# define A_FLAG 2
# define R_FLAG 4
# define LIL_R_FLAG 8
# define T_FLAG 16
// define the rest of the flags


typedef	struct	s_flags
{
	int		l;
	int		a;
	int		r;
	int		t;
	int		ur;
    int     exec;
}				t_flags;

typedef struct s_dir
{
    DIR     *dir;
    char    *name;
    char    type;
}              t_dir;

typedef struct s_c_list
{
    t_dir  *dir;
    struct s_c_list *next;
}              t_c_list;

typedef struct s_sys
{
    DIR      *dir;

}              t_sys;


t_c_list    *sortedmerge(t_c_list *a, t_c_list *b); 
void	frontbacksplit(t_c_list *source, t_c_list **frontref, t_c_list **backref); 
void	sort_data(t_c_list **headRef);
void	recurse(char *directory, int *exec);
void	big_r_flag();
void	r_push(t_c_list **head_ref, char *str, int type);
void	r_push_dirs(t_c_list **head_ref, char *str);
void	no_flag(char *directory);
void	a_flag();
void	get_flag(char *argv);
void    ls_push(t_c_list **head_ref, char *str);
void	do_ls(char *directory);
void	parse_flags(int argc, char **argv);
void	print_list(t_c_list *head);
void	find_flags(t_flags *flags, char *argv);
#endif