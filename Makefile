# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvillemi <mvillemi@student.42.fr           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/30 20:03:48 by mvillemi          #+#    #+#              #
#*   Updated: 2017/10/07 02:10:16 by mvillemi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

ifndef CUR_PROJECT_PWD
 export CUR_PROJECT_PWD := $(shell /bin/pwd)
endif

CHECKER  := "checker_files"
PUSH_SWAP := "push_swap_files"

all:
	@make -C $(PUSH_SWAP) && cp $(PUSH_SWAP)/push_swap $(CUR_PROJECT_PWD)/.;
	@make -C $(CHECKER) && cp $(CHECKER)/checker $(CUR_PROJECT_PWD)/.;


clean:
	@make -C $(CHECKER) clean;
	@make -C $(PUSH_SWAP) clean;

fclean:
	@rm -f "checker";
	@rm -f "push_swap";
	@make -C $(CHECKER) fclean;
	@make -C $(PUSH_SWAP) fclean;

push_swap:
	@make -C $(PUSH_SWAP);

checker:
	@make -C $(CHECKER);

re: fclean all

test: all
	@perl ops.pl
	./run.sh

debug: clean
	@make DEBUG=1 -C $(PUSH_SWAP) && cp $(PUSH_SWAP)/push_swap $(CUR_PROJECT_PWD)/.;
	@make DEBUG=1 -C $(CHECKER) && cp $(CHECKER)/checker $(CUR_PROJECT_PWD)/.;

.PHONY: all clean fclean re push_swap checker debug
.SILENT:
