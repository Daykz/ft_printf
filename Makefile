# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/24 23:55:34 by dmathe            #+#    #+#              #
#    Updated: 2015/04/29 16:54:39 by dmathe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRCS = di_len.c ft_lotoa.c ft_mutoa.c ft_sizehtoa.c \
ft_utoa.c o_len2.c  x_len.c di_len2.c ft_ltoa.c ft_otoa.c ft_sizeotoa.c \
precis.c x_len2.c base.c flag.c ft_lutoa.c ft_printf.c ft_sizetoa.c \
limits.c precis2.c xmaj_len.c check_convers.c ft_hmtoa.c ft_mhmtoa.c \
check_precis.c ft_htoa.c ft_mhtoa.c ft_shmtoa.c ft_sotoa.c mask.c u_len.c \
convers.c ft_lhmtoa.c ft_motoa.c ft_shtoa.c ft_stoa.c modif_len.c u_len2.c \
convers2.c ft_lhtoa.c ft_mtoa.c ft_sizehmtoa.c ft_sutoa.c o_len.c \
ft_sizeutoa.c main.c precision.c xmaj_len2.c zero1.c zero.c useles_char.c

OBJS =		$(SRCS:.c=.o)

INCLUDES =	-I libft \
			-I includes

LIBS =		-L libft/ -lft \

FLAGS =		-g -Wall -Wextra -Werror


$(NAME):	$(OBJS)
	@make -C libft/ fclean
	@make -C libft/
	@echo "Create binary"
	@gcc -o $(NAME) $(OBJS) $(LIBS)
	@echo "Complitation ok"

$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

clean:
	rm -f	$(OBJS)

fclean: clean
	rm -f	$(NAME)

re: fclean all

.PHONY:	 all clean fclean re
