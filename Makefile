#                                                         :::      ::::::::    #
#    make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/21 04:14:19 by mvillemi          #+#    #+#              #
#*   Updated: 2017/04/18 17:58:25 by mvillemi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Define racine path if it does not exit.
ifndef CUR_PROJECT_PWD
	export CUR_PROJECT_PWD := $(shell /bin/pwd)
endif

NAME			:= push_swap

all: $(NAME)

$(NAME) : 
	make -C libs/libft
	make -C libs/liblst
	make -C sources/exec
	#make -C sources/checker 
	#make -C sources/push_swap

clean :
	make -C libs/libft clean
	make -C libs/liblst clean
	#make -C sources/exec clean
	#make -C sources/checker clean
	#make -C sources/push_swap clean

fclean : 
	make -C libs/libft fclean
	make -C libs/liblst fclean
	#make -C sources/exec fclean
	#make -C sources/checker fclean
	#make -C sources/push_swap fclean

ps :
	make -C sources/exec
	make -C sources/checker
	make -C sources/push_swap

psfclean :
	make -C sources/exec fclean
	make -C sources/checker fclean
	make -C sources/push_swap fclean

re : fclean all

.SILENT:
