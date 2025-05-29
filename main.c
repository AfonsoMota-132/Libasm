/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:53:47 by afogonca          #+#    #+#             */
/*   Updated: 2025/05/29 13:15:28 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void *data;
	struct s_list *next;
}	t_list;

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *str1, char *str2);
int		ft_write(int fd, char *str, int len);
char	*ft_strdup(const char *str);
void	ft_list_push_front(t_list **begin_list, void *data);
size_t	ft_list_size(t_list	*list);

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		printf("%lu\n", ft_strlen(av[1]));
		char	dest[100] = "HELLOaaaaa";
		printf("%s\n", dest);
		char	*idk = ft_strcpy(dest, av[1]);
		int		strcmp = ft_strcmp ("He", av[1]);
		ft_write(0, dest, ft_strlen(dest));
		ft_write(0, "\t", 1);
		ft_write(0, idk, ft_strlen(idk));
		ft_write(0, "\t", 1);
		printf("%i\n", strcmp);
		char	*dup = ft_strdup(dest);
		ft_write(0, dup, ft_strlen(dup));
		ft_write(0, "\n", 1);
		free(dup);
		t_list	*head = malloc(sizeof(t_list));
		head->data = ft_strdup(av[1]);
		t_list	*tmp;
		head->next = NULL;
		tmp = head;
		for (int i = 0; i <= 2; i++)
		{
			tmp->next = malloc(sizeof(t_list));
			tmp = tmp->next;
		}
		tmp->next = NULL;
		printf("%lu\n", ft_list_size(head));
		ft_write(0, head->data, ft_strlen(head->data));
		ft_write(0, "\n", 1);
		ft_list_push_front(&head, "HELLLLOOOO");
		ft_write(0, head->data, ft_strlen(head->data));
		ft_write(0, "\n", 1);
	}

}
