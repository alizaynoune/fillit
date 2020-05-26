# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agym <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 22:48:22 by agym              #+#    #+#              #
#    Updated: 2019/05/16 20:49:46 by alzaynou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
GCC = gcc -Wall -Wextra -Werror
_PATH_FILE = ./src/
_PATH_LIBFT = ./libft/
_LIBFT = -lft
_PATH_INC = ./includes/
_PATH_OBJ = ./objs/
_INC_SRC = fillit.h


SRC_FILE = ft_backtrack.c			\
	   ft_error_and_free.c			\
	   ft_check_and_stock.c			\
	   ft_min_y_x.c				\
	   ft_to_map.c				\
	   main.c				\
	   ft_display.c

INC = $(addprefix $(_PATH_INC), $(_INC_SRC))
OBJS = $(addprefix $(_PATH_OBJ), $(SRC_FILE:.c=.o))

DEF = \e[0m
RED = \e[1;31m
PURPLR = \e[1;34m
BLUE = \e[1;96m
GREEN = \e[1;32m
SILVER = \e[1;90m
YELLOW = \e[1;33m

define compile
@mkdir -p $(_PATH_OBJ)
@$(GCC) -c $1 -o $2 -I $(_PATH_INC)
@echo "$(SILVER)[$(PURPLR)Object file$(BLUE) $(notdir $2)$(SILVER)] $(GREEN)Created.$(DEF)"
endef

all: $(NAME)

$(NAME) : $(OBJS)
	@make -s -C libft/
	@gcc $(OBJS) -L $(_PATH_LIBFT) $(_LIBFT) -o $(NAME)
	@echo "$(SILVER)[$(PURPLR)Binary file$(YELLOW) $(notdir $(NAME))$(SILVER)] $(GREEN)Created.$(DEF)"

$(_PATH_OBJ)%.o: $(_PATH_FILE)%.c
	@$(call compile, $<, $@)

clean :
	@rm -rf $(_PATH_OBJ) 
	@make -s -C libft clean
	@echo "$(SILVER)[$(PURPLR)Object's path$(BLUE) $(_PATH_OBJ)$(SILVER)] $(RED)Deleted.$(DEF)"

fclean : clean
	@rm -rf $(NAME)
	@make -s -C libft fclean
	@echo "$(SILVER)[$(PURPLR)Binary file$(YELLOW) $(notdir $(NAME))$(SILVER)] $(RED)Deleted.$(DEF)"

re : fclean all

.PHONY : all clean fclean re
