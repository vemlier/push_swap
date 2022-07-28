# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 12:46:09 by chukim            #+#    #+#              #
#    Updated: 2022/05/26 12:28:42 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = push_swap.a
FT_PRINTFDIR	= ./ft_printf
FT_PRINTFFILE	= libftprintf.a

CC              = gcc
CFLAGS  = -Wall -Wextra -Werror
AR              = ar rcs
RM              = rm -f

SRCS    = push_swap.c \
			preprocessor.c \
			stack_making.c \
			stack_printing.c \
			stack_basic.c \
			stack_push_swap1.c \
			stack_push_swap2.c \
			stack_arr.c \
			error.c \
			sorting_a.c \
			sorting_b.c \
			quick_sorting.c \
			main_sorting1.c \
			main_sorting2.c \
			sorting_5.c \
			opt_op.c \

OBJS    = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS)
		make -C $(FT_PRINTFDIR)
		cp $(FT_PRINTFDIR)/$(FT_PRINTFFILE) $(NAME)
		$(AR) $@ $?

all : $(NAME)

clean :
		make -C $(FT_PRINTFDIR) clean
		$(RM) $(OBJS)

fclean : clean
		make -C $(FT_PRINTFDIR) fclean
		$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus