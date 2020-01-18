
#include "ft_ls.h"

char		*write_mods_rights(mode_t st_mode)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 11);
	str[0] = S_ISDIR(st_mode) ? 'd' : '-';
	if (S_ISLNK(st_mode))
		str[0] = 'l';
	if (S_ISBLK(st_mode))
		str[0] = 'b';
	if (S_ISCHR(st_mode))
		str[0] = 'c';
	if (S_ISFIFO(st_mode))
		str[0] = 'p';
	if (S_ISSOCK(st_mode))
		str[0] = 's';
	str[1] = st_mode & S_IRUSR ? 'r' : '-';
	str[2] = st_mode & S_IWUSR ? 'w' : '-';
	str[3] = st_mode & S_IXUSR ? 'x' : '-';
	str[4] = st_mode & S_IRGRP ? 'r' : '-';
	str[5] = st_mode & S_IWGRP ? 'w' : '-';
	str[6] = st_mode & S_IXGRP ? 'x' : '-';
	str[7] = st_mode & S_IROTH ? 'r' : '-';
	str[8] = st_mode & S_IWOTH ? 'w' : '-';
	str[9] = st_mode & S_IXOTH ? 'x' : '-';
	str[10] = '\0';
	return (str);
}


void	l_contents(t_c_list *c_list, struct dirent *sd, struct stat *s)
{
	struct group	*group;
	struct passwd	*user;

	ls_push(&c_list, sd->d_name);
	c_list->list = (t_l *)malloc(sizeof(t_l));
	c_list->list->rights = write_mods_rights(s->st_mode);
	c_list->list->links = s->st_nlink;
	user = getpwuid(s->st_uid);
	group = getgrgid(s->st_gid);
	c_list->list->owner_name = ft_strdup(user->pw_name);
	c_list->list->group_name = ft_strdup(group->gr_name);
	c_list->list->byte_size = s->st_size;
	c_list->list->time = ctime(&s->st_mtimespec.tv_nsec);
}

void	do_l(char *directory)
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
			if (sd->d_name[0] != '.')
			{
				lstat(sd->d_name, &s);
				l_contents(c_list, sd, &s);
			}
		}
		printf("hello :)");
		closedir(dir);
		sort_data(&c_list);
		//print_list(c_list);
		while (c_list != NULL)
		{
			printf("hi");
			printf("%s\n", c_list->dir->name);
			c_list = c_list->next;
		}
	}
}
