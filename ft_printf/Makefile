# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 11:18:20 by chukim            #+#    #+#              #
#    Updated: 2022/10/29 17:29:40 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs
INCLUDES	= ./includes/ft_printf.h
SRCS		= ./srcs/ft_printf.c \
				./srcs/ft_printf_parse.c \
				./srcs/ft_printf_char.c \
				./srcs/ft_printf_string.c \
				./srcs/ft_printf_num.c \
				./srcs/ft_printf_num_utils.c
OBJS	= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $@ $?

all : $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFTDIR) 

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFTDIR)
	
re : fclean all

.PHONY : all clean fclean re