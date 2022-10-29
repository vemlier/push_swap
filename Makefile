# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 12:46:09 by chukim            #+#    #+#              #
#    Updated: 2022/10/29 18:03:15 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap.a
FT_PRINTFDIR	= ./ft_printf
FT_PRINTFFILE	= libftprintf.a
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
AR				= ar rcs
INCLUDES		= ./includes/push_swap.h
SRCS    = ./srcs/push_swap.c ./srcs/preprocessor.c ./srcs/stack_making.c ./srcs/stack_printing.c \
			./srcs/stack_basic.c ./srcs/stack_push_swap1.c ./srcs/stack_push_swap2.c ./srcs/stack_arr.c \
			./srcs/error.c ./srcs/sorting_a.c ./srcs/sorting_b.c ./srcs/quick_sorting.c \
			./srcs/main_sorting1.c ./srcs/main_sorting2.c ./srcs/sorting_5.c ./srcs/opt_op.c
OBJS    = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		make -C $(FT_PRINTFDIR)
		cp $(FT_PRINTFDIR)/$(FT_PRINTFFILE) $(NAME)
		$(AR) $@ $?

all : $(NAME)

clean :
	$(RM) $(OBJS)
	make -C $(FT_PRINTFDIR) clean
		

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(FT_PRINTFDIR)

re : clean all

.PHONY : all clean fclean re