# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 08:57:19 by afogonca          #+#    #+#              #
#    Updated: 2025/05/29 13:46:05 by afogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
NAME_TEST = test

ASM_FLAGS = -f elf64 -g
NASM = nasm

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_calloc.s
OBJS = $(SRCS:.s=.o)

TSRCS =	main.c
TOBJS = $(TSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.s
	$(NASM) $(ASM_FLAGS) -s $< -o $@

clean:
	rm -f $(OBJS) $(TOBJS)

fclean: clean
	rm -f $(NAME) $(NAME_TEST)

test: all $(TOBJS)
	$(CC) $(CFLAGS) $(TOBJS) $(OBJS) -o $(NAME_TEST)

re: fclean all
