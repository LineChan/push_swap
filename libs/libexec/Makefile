# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvillemi <mvillemi@student.42.fr           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/06 14:10:37 by mvillemi          #+#    #+#              #
#    Updated: 2017/10/07 00:16:58 by mvillemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define racine path if not exist.
ifndef CUR_PROJECT_PWD
 export CUR_PROJECT_PWD := $(shell /bin/pwd)
endif

NAME			:= libexec.a
NAME_CLEAR		:= libexec

# Directories
INCS			:= includes
SRCS			:= sources
LIBS			:= $(CUR_PROJECT_PWD)/libs
OBJS			:= objs

# Libaries
LIB 			:= "libft liblst"

# Subdirectories
SRCS_DIR		:= $(shell find $(SRCS) -type d)
OBJS_DIR		:= $(addprefix $(OBJS)/,$(SRCS_DIR))

# Includes
INCS_FILES		:= -I$(INCS)/
INCS_FILES 		+= $(shell echo "$(foreach i, $(shell echo "$(LIB)"), -I$(LIBS)/$(i)/$(INCS))")

# Libraries link
LIBS_FILES		:= $(shell echo "$(foreach i, $(shell echo "$(LIB)"), -L $(LIBS)/$(i) -$(shell basename "$(i)" | sed 's/lib/l/g'))")

# Files
SRCS_FILES		:= $(shell find $(SRCS) -type f)
OBJS_FILES		:= $(SRCS_FILES:%.c=$(OBJS)/%.o)

# Compiler and shell
CC				:= gcc
SIZE			:= $(shell echo "$(shell tput cols) - 16" | bc)
INCLUDES		:= -I$(INCS)
RM				:= rm -rf

# Flags, depends on user input: `make DEBUG=1'
ifeq ($(DEBUG),1)
C_FLAGS		 	:= -MMD -g -DDEBUG -Wall -Wextra -Werror
else
C_FLAGS		 	:= -MMD -g -Wall -Wextra -Werror
endif

# Colors
RED				= \033[31;1m
GREEN		    = \033[32;1m
YELLOW			= \033[33;1m
BLUE			= \033[34;1m
PURPLE			= \033[35;1m
CYAN			= \033[36;1m
LGREY			= \033[37;1m
END_C			= \033[m
CLEAR			= "\033[K"

# String
PRINT_KO        = printf "  [$(RED)✗$(END_C)]    $(RED)-->$(END_C)    %-*s\033[0m\r" "$(SIZE)"
PRINT_OK        = printf "  [$(GREEN)✓$(END_C)]   $(GREEN)%s$(END_C)\n"


# Create objs directory and all subdirectories
$(shell mkdir -p $(OBJS) $(OBJS_DIR))

all :
	make $(NAME)

$(NAME) : $(OBJS_FILES)
	$(foreach i,$(shell echo "$(LIB)"),make -C "$(LIBS)/$(i)";)
	ar rc $@ $^ && printf $(CLEAR) && $(PRINT_OK) "$(NAME_CLEAR)"

$(OBJS)/%.o: %.c
	$(CC) $(C_FLAGS) $(INCS_FILES) -c $< -o $@ && $(PRINT_KO) $< || exit

l :
	$(RM) lem-in
	make $(NAME)

clean :
	$(RM) $(OBJS)
	$(foreach i,$(shell echo "$(LIB)"),make -C "$(LIBS)/$(i)" clean;)

fclean : clean
	$(RM) $(NAME)
	$(foreach i,$(shell echo "$(LIB)"),make -C "$(LIBS)/$(i)" fclean;)

debug : fclean
	make DEBUG=1

re : fclean all

.PHONY : all clean fclean setup re test
.SILENT:
