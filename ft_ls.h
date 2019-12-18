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

typedef struct s_sys
{
    
}              t_sys;



#endif