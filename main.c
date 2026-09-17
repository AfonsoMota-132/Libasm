/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:53:47 by afogonca          #+#    #+#             */
/*   Updated: 2026/09/16 13:58:21 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*ft_calloc(size_t n, size_t bytes);

int	main(int ac, char **av)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	test_calloc();
	(void) ac;
	(void) av;
}

char *strings[] = {"Test", "ABC", "aBcDefGH", "Hello_WOrld!", "   ",
	"Banana", "Terracota", "Pie", "Vicinity of obscenity", ""};

char *strings2[] = {"ABC", "aBcDefGH", "Test", "   ", "",
	"Terracota", "Banana", "Vicinity of obscenity", "Pie", "Hello_World!"};

void test_strlen(void)
{
	printf("[ft_strlen]\n");
	for (int i = 0; i < NBR_STRS; i++) {
		if (ft_strlen(strings[i]) != strlen(strings[i])) {
			printf(KO);
		} else {
			printf(OK);
		}
	}
}

void test_strcpy(void)
{
	char dest1[100];
	char dest2[100];

	printf("[ft_stlcpy]\n");
	for (int i = 0; i < NBR_STRS; i++) {
		if (strcmp(ft_strcpy(dest1, strings[i]), strcpy(dest2, strings[i])) != 0) {
			printf(KO);
		} else {
			printf(OK);
		}
	}
}

void test_strcmp(void)
{
	printf("[ft_strcmp]\n");
	for (int i = 0; i < NBR_STRS; i++) {
		if (ft_strcmp(strings[i], strings2[i]) * strcmp(strings[i], strings2[i]) < 0) {
			printf(KO);
		} else {
			printf(OK);
		}
	}
}

void test_write(void)
{
	int		fd;
	ssize_t	ret1;
	ssize_t	ret2;

	printf("[ft_write]\n");

	/* 1) Normal writes to a valid fd */
	fd = open("/tmp/ft_write_test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	for (int i = 0; i < NBR_STRS; i++) {
		ret1 = ft_write(fd, strings[i], ft_strlen(strings[i]));
		ret2 = write(fd, strings[i], strlen(strings[i]));
		if (ret1 != ret2) {
			printf(KO);
		} else {
			printf(OK);
		}
	}
	close(fd);

	/* 2) Invalid fd -> should return -1 and set errno to EBADF */
	errno = 0;
	ret1 = ft_write(-1, "test", 4);
	int errno1 = errno;

	errno = 0;
	ret2 = write(-1, "test", 4);
	int errno2 = errno;

	if (ret1 == ret2 && ret1 == -1 && errno1 == errno2) {
		printf(OK);
	} else {
		printf(KO);
	}

	/* 3) Writing to a read-only fd -> should also fail with EBADF */
	fd = open("/tmp/ft_write_test.txt", O_RDONLY);
	errno = 0;
	ret1 = ft_write(fd, "test", 4);
	errno1 = errno;

	errno = 0;
	ret2 = write(fd, "test", 4);
	errno2 = errno;
	close(fd);

	if (ret1 == ret2 && ret1 == -1 && errno1 == errno2) {
		printf(OK);
	} else {
		printf(KO);
	}
}

void test_read(void)
{
	int		fd1;
	int		fd2;
	char	buf1[1024];
	char	buf2[1024];
	ssize_t	ret1;
	ssize_t	ret2;
	int		errno1;
	int		errno2;

	printf("[ft_read]\n");

	/* 1) Normal read from a valid fd, compare return value and content */
	fd1 = open("/tmp/ft_write_test.txt", O_RDONLY);
	fd2 = open("/tmp/ft_write_test.txt", O_RDONLY);

	ret1 = ft_read(fd1, buf1, sizeof(buf1));
	ret2 = read(fd2, buf2, sizeof(buf2));

	if (ret1 != ret2 || memcmp(buf1, buf2, ret1) != 0) {
		printf(KO);
	} else {
		printf(OK);
	}
	close(fd1);
	close(fd2);

	/* 2) Invalid fd -> should return -1 and set errno to EBADF */
	errno = 0;
	ret1 = ft_read(-1, buf1, sizeof(buf1));
	errno1 = errno;

	errno = 0;
	ret2 = read(-1, buf2, sizeof(buf2));
	errno2 = errno;

	if (ret1 == ret2 && ret1 == -1 && errno1 == errno2) {
		printf(OK);
	} else {
		printf(KO);
	}

	/* 3) Reading from a write-only fd -> should fail with EBADF */
	fd1 = open("/tmp/ft_write_test.txt", O_WRONLY);
	fd2 = open("/tmp/ft_write_test.txt", O_WRONLY);

	errno = 0;
	ret1 = ft_read(fd1, buf1, sizeof(buf1));
	errno1 = errno;

	errno = 0;
	ret2 = read(fd2, buf2, sizeof(buf2));
	errno2 = errno;

	close(fd1);
	close(fd2);

	if (ret1 == ret2 && ret1 == -1 && errno1 == errno2) {
		printf(OK);
	} else {
		printf(KO);
	}

	/* 4) Read from a file at EOF -> should return 0, not an error */
	fd1 = open("/tmp/ft_write_test.txt", O_RDONLY);
	fd2 = open("/tmp/ft_write_test.txt", O_RDONLY);

	/* Drain both fds first so the next read hits EOF */
	while (ft_read(fd1, buf1, sizeof(buf1)) > 0)
		;
	while (read(fd2, buf2, sizeof(buf2)) > 0)
		;

	ret1 = ft_read(fd1, buf1, sizeof(buf1));
	ret2 = read(fd2, buf2, sizeof(buf2));

	close(fd1);
	close(fd2);

	if (ret1 == ret2 && ret1 == 0) {
		printf(OK);
	} else {
		printf(KO);
	}
}

void test_strdup(void)
{
	char	*dup1;
	char	*dup2;

	printf("[ft_strdup]\n");
	for (int i = 0; i < NBR_STRS; i++) {
		dup1 = ft_strdup(strings[i]);
		dup2 = strdup(strings[i]);

		if (!dup1 || !dup2 || strcmp(dup1, dup2) != 0 || dup1 == strings[i]) {
			printf(KO);
		} else {
			printf(OK);
		}
		free(dup1);
		free(dup2);
	}
}

void	test_calloc(void)
{
	unsigned char	*buffer;

	printf("[ft_calloc]\n");
	buffer = ft_calloc(8, sizeof(*buffer));
	if (!buffer)
		printf(KO);
	else if (buffer[0] != 0 || buffer[7] != 0)
		printf(KO);
	else
		printf(OK);
	free(buffer);

	buffer = ft_calloc((size_t)-1, 2);
	if (buffer != NULL)
		printf(KO);
	else
		printf(OK);
}
