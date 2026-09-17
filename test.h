/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 08:08:29 by afogonca          #+#    #+#             */
/*   Updated: 2026/09/16 08:10:49 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define NBR_STRS 10

typedef struct s_list
{
	void *data;
	struct s_list *next;
}	t_list;

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *str1, char *str2);
int		ft_write(int fd, char *str, int len);
int		ft_read(int fd, char *str, int len);
char	*ft_strdup(const char *str);
// void	ft_list_push_front(t_list **begin_list, void *data);
// sizeo_t	ft_list_size(t_list	*list);

void	test_strlen(void);
void	test_strcpy(void);
void	test_strcmp(void);
void	test_write(void);
void	test_read(void);
void	test_strdup(void);

# define OK			"\033[42m[OK]\033[00m\n"
# define KO			"\033[41m[KO]\033[00m\n"

#endif
