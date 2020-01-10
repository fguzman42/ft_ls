
#include "ft_ls.h"


void	content(t_c_list *list, int exec, struct dirent *sd)
{
	struct stat s;

	if (exec == 1)
		ls_push(&list, sd->d_name, 0);
	if (exec == 3)
		ls_push()
}

void	do_l(char *directory, int exec)
{
	DIR *dir;
	struct dirent *sd;
	t_c_list  *c_list;
	struct stat s;

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
				ls_push(&c_list, sd, 0);
            //if (exec == 3)
				ls_push
			else if (sd->d_name[0] != '.')
				ls_push(&c_list, sd->d_name);
		}
		closedir(dir);
		sort_data(&c_list);
		print_list(c_list);
	}
}
