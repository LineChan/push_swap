#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/04/17 15:25:36 by mvillemi          #+#    #+#             *#
#*   Updated: 2017/04/21 09:34:45 by mvillemi         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME				:= push_swap

# Directories
SRCS				:= srcs
OBJS				:= objs
INCS				:= includes

# Subdirectories
SRCS_DIR			:= $(shell find $(SRCS) -type d)
OBJS_DIR			:= $(addprefix $(OBJS)/, $(SRCS_DIR))
INCS_DIR			:= ../../$(INCS)

# Paths
LIBFT_PATH			:= ../../libft
LIBLST_PATH			:= ../../liblst
EXEC_PATH			:= ../exec

# Libraries
LFT					:= -L$(LIBFT_PATH) -lft
LLST				:= -L$(LIBLST_PATH) -llst
LEXEC				:= -L$(EXEC_PATH) -lexec

LIBRARIES			:= $(LFT) $(LLST) $(LEXEC)

# Files
SRCS_FILES			:= $(shell find $(SRCS_DIR) -type f)
OBJS_FILES			:= $(SRCS_FILES:%.c=$(OBJS)/%.o)
INCS_FILES			:= $(shell find $(INCS_DIR) -type f)

# Compiler and shell
CC					:= gcc
CFLAGS				:= -Werror -Wall -Wextra
RM					:= rm -rf
SIZE				:= $(shell echo "$(shell tput cols) - 16" | bc)
INCLUDES			:= -I$(INCS_DIR)

# Colors
RED					= \033[31;1m
GREEN				= \033[32;1m
YELLOW				= \033[33;1m
BLUE				= \033[34;1m
PURPLE				= \033[35;1m
CYAN				= \033[36;1m
LGREY				= \033[37;1m
END_C				= \033[m

# String
PRINT_KO	= printf "  [$(RED)✗$(END_C)]    $(RED)-->$(END_C)    %-*s\r\033[m" "$(SIZE)"
PRINT_OK	= printf "  [$(GREEN)✓$(END_C)]   $(GREEN)%s$(END_C)\n" 

# Creates objs directory and all subdirectories
$(shell mkdir -p $(OBJS) $(OBJS_DIR))

all :
	make -j $(NAME)

$(NAME) : $(OBJS_FILES) 
	$(CC) $(CFLAGS) -o $@ $(INCLUDES) $(OBJS_FILES) $(LIBRARIES)
	mv $(NAME) ../../
	printf "\033[K"
	$(PRINT_OK) $(NAME)

$(OBJS)/%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ && $(PRINT_KO) $< || exit

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) ../../$(NAME)

re : fclean all

.PHONY : all clean fclean setup re
.SILENT :
