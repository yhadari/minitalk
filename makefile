# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 18:41:22 by yhadari           #+#    #+#              #
#    Updated: 2021/06/15 16:02:59 by yhadari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
BONUS = bonus

FTS = server.c ft_putnbr_fd.c
FTC = client.c ft_atoi.c
FTSB = bonus/server_bonus.c bonus/ft_putnbr_fd_bonus.c bonus/dectobin_bonus.c
FTCB = bonus/client_bonus.c bonus/ft_atoi_bonus.c bonus/dectobin_bonus.c

server = server
client = client
server_bonus = server_bonus
client_bonus = client_bonus

all : $(NAME)

$(NAME) : $(server) $(client)

$(server) :
	@gcc -Wall -Wextra -Werror $(FTS) -o $(server)

$(client) :
	@gcc -Wall -Wextra -Werror $(FTC) -o $(client)

$(BONUS) : $(server_bonus) $(client_bonus)

$(server_bonus) :
	@gcc -Wall -Wextra -Werror $(FTSB) -o $(server_bonus)

$(client_bonus) :
	@gcc -Wall -Wextra -Werror $(FTCB) -o $(client_bonus)

clean :
	@rm  -f *.o

fclean : clean
	@rm -f $(server) $(client) $(server_bonus) $(client_bonus)

re : fclean all