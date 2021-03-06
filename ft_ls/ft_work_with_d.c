/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 18:46:08 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/26 14:16:42 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int	ft_check_if_flag_contains(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_work_with_d(char *path, char *flag)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				close_dir;
	t_ls_list		*start;
	struct stat		*buf;
	char			*lbuf;
	ssize_t			readlink_return;

				buf = (struct stat*)malloc(sizeof(*buf));
				(void)lstat(path, buf);
				if (S_ISLNK(buf->st_mode) == 1)
				{
					lbuf = (char*)malloc(1024);
					readlink_return = readlink(path, lbuf, 1024);
					lbuf[readlink_return] = '\0';
				}
	if ((ft_get_file_type_2(path) == 'd' && ft_check_if_flag_contains(flag, 'd') == 0) || (ft_get_file_type_2(path) == 'l' && ft_check_if_flag_contains(flag, 'l') == 0 && ft_get_file_type_2(lbuf) == 'd'))
	{
		dirp = opendir(path);
		if (dirp == NULL)
		{
			if (g_targets_number >= 2)
			{
				if (ft_first_valid_directory_target() != 1)
					ft_putchar('\n');
				ft_putstr(path);
				ft_putstr(":\n");
			}
			ft_putstr("ls: ");
			perror(path);
		}
		if (dirp != NULL)
		{
			start = NULL;
			while ((dp = readdir(dirp)) != NULL)
			{
				if (dp == NULL)
					perror("readdir error");
				buf = (struct stat*)malloc(sizeof(*buf));
				(void)lstat(ft_strjoin(ft_strjoin(path, "/"), dp->d_name), buf);
				if (S_ISLNK(buf->st_mode) == 1)
				{
					lbuf = (char*)malloc(1024);
					readlink_return = readlink(ft_strjoin(ft_strjoin(path, "/"), dp->d_name), lbuf, 1024);
					lbuf[readlink_return] = '\0';
				}
				else
					lbuf = ft_strdup("");
				if (ft_check_if_flag_contains(flag, 't') == 1 || ft_check_if_flag_contains(flag, 'f') == 1)
				{
					ft_push_sort_lsl0(&start, dp->d_name, buf->st_blocks, lbuf);
					ft_push_sort_lsl2(start, dp->d_name, buf->st_size, buf->st_mtime);
					ft_push_sort_lsl3(start, dp->d_name, buf->st_uid, buf->st_gid);
					ft_push_sort_lsl4(start, dp->d_name, buf->st_nlink, buf->st_mode);
					ft_push_sort_lsl5(start, dp->d_name, listxattr(ft_strjoin(ft_strjoin(path, "/"), dp->d_name), NULL, 0, XATTR_NOFOLLOW), buf->st_atime);
				}
				else	/* sort by ascii */
				{
					ft_push_sort_lsl(&start, dp->d_name, buf->st_blocks, lbuf);
					ft_push_sort_lsl2(start, dp->d_name, buf->st_size, buf->st_mtime);
					ft_push_sort_lsl3(start, dp->d_name, buf->st_uid, buf->st_gid);
					ft_push_sort_lsl4(start, dp->d_name, buf->st_nlink, buf->st_mode);
					ft_push_sort_lsl5(start, dp->d_name, listxattr(ft_strjoin(ft_strjoin(path, "/"), dp->d_name), NULL, 0, XATTR_NOFOLLOW), buf->st_atime);
				}
			}
			if (ft_check_if_flag_contains(flag, 'f') == 1)
				flag = ft_enable_flag_a(flag, 'a');
			if (ft_check_if_flag_contains(flag, 'a') == 0)
				ft_delete_hidden_from_list(&start);
			ft_push_bsl_bnl_to_list(start);
			ft_push_buidl_bgidl_to_list(start);
			if (ft_check_if_flag_contains(flag, 'S') == 1)
			{
				ft_sort_list_by_bytes_size(start);
				ft_sort_list_by_ascii_for_bytes_size_equal(start);
			}
			else if (ft_check_if_flag_contains(flag, 't') == 1 && ft_check_if_flag_contains(flag, 'u') == 1)
			{
				ft_sort_list_by_atime(start);
				ft_sort_list_by_ascii_for_atime_equal(start);
			}
			else if (ft_check_if_flag_contains(flag, 't') == 1)
			{
				ft_sort_list_by_mtime(start);
				ft_sort_list_by_ascii_for_mtime_equal(start);
			}
			if (ft_check_if_flag_contains(flag, 'r') == 1)
				ft_sort_list_reverse(start, flag);
			if (g_targets_number >= 2)
			{
				if (ft_first_valid_directory_target() != 1)
					ft_putchar('\n');
				ft_putstr(path);
				ft_putstr(":\n");
			}
			if (ft_check_if_flag_contains(flag, 'R') == 1)
			{	g_targets_number++;
				ft_first_valid_directory_target();
			}
			ft_putlist_lsl(start, flag);
			close_dir = closedir(dirp);
			if (close_dir == -1)
				perror("closedir error");
		}
		if (dirp != NULL && (ft_check_if_flag_contains(flag, 'R') == 1))
		{
			while (start)
			{
				if (ft_strcmp(start->name, ".") != 0 && ft_strcmp(start->name, "..") != 0 )
				{
					(void)lstat(ft_strjoin(ft_strjoin(path, "/"), start->name), buf);
					if (S_ISDIR(buf->st_mode) == 1)
						ft_work_with_d(ft_strjoin(ft_strjoin(path, "/"), start->name), flag);
				}
				start = start->next;
			}
		}
	}
}
