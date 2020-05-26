# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/31 14:45:40 by alzaynou          #+#    #+#              #
#    Updated: 2019/04/07 16:57:27 by alzaynou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCC = gcc -c -Wall -Werror -Wextra
PATH_SRC = ./src/
PATH_INC = ../includes/
PATH_OBJ = ./objs/

FILE_SRC = ft_atoi.c		\
	   ft_bzero.c		\
	   ft_isalnum.c		\
	   ft_isalpha.c		\
	   ft_isascii.c		\
	   ft_isdigit.c		\
	   ft_isprint.c		\
	   ft_itoa.c		\
	   ft_lstadd.c		\
	   ft_lstdel.c		\
	   ft_lstdelone.c	\
	   ft_lstiter.c		\
	   ft_lstmap.c		\
	   ft_lstnew.c		\
	   ft_memalloc.c	\
	   ft_memccpy.c		\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_memcpy.c		\
	   ft_memdel.c		\
	   ft_memmove.c		\
	   ft_memset.c		\
	   ft_putchar.c		\
	   ft_putchar_fd.c	\
	   ft_putendl.c		\
	   ft_putendl_fd.c	\
	   ft_putnbr.c		\
	   ft_putnbr_fd.c	\
	   ft_putstr.c		\
	   ft_putstr_fd.c	\
	   ft_strcat.c		\
	   ft_strchr.c		\
	   ft_strclr.c 		\
	   ft_strcmp.c 		\
	   ft_strcpy.c 		\
	   ft_strdel.c 		\
	   ft_strdup.c 		\
	   ft_strequ.c 		\
	   ft_striter.c 	\
	   ft_striteri.c 	\
	   ft_strjoin.c 	\
	   ft_strlcat.c 	\
	   ft_strlen.c 		\
	   ft_strmap.c 		\
	   ft_strmapi.c 	\
	   ft_strncat.c 	\
	   ft_strncmp.c 	\
	   ft_strncpy.c 	\
	   ft_strnequ.c 	\
	   ft_strnew.c 		\
	   ft_strnstr.c 	\
	   ft_strrchr.c 	\
	   ft_strsplit.c 	\
	   ft_strstr.c 		\
	   ft_strsub.c 		\
	   ft_strtrim.c 	\
	   ft_tolower.c 	\
	   ft_toupper.c		\
	   get_next_line.c

INC_SRC = libft.h		\
	  get_next_line.h

OBJS = $(addprefix $(PATH_OBJ), $(FILE_SRC:.c=.o))

INC = $(addprefix $(PATH_INC), $(INC_SRC))

DEF = \e[0m
RED = \e[1;31m
PURPLR = \e[1;34m
BLUE = \e[1;96m
GREEN = \e[1;32m
SILVER = \e[1;90m
YELLOW = \e[1;33m

define compile
@mkdir -p $(PATH_OBJ)
@$(GCC) $1 -o $2 -I $(PATH_INC)
@echo "$(SILVER)[$(PURPLR)Object file$(BLUE) $(notdir $2)$(SILVER)] $(GREEN)Created.$(DEF)"
endef

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(SILVER)[$(PURPLR)Library file$(YELLOW) $(notdir $(NAME))$(SILVER)] $(GREEN)Created.$(DEF)"

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(INC)
	$(call compile, $<, $@)
clean:
	@rm -rf $(PATH_OBJ)
	@echo "$(SILVER)[$(PURPLR)Object's path$(BLUE) $(PATH_OBJ)$(SILVER)] $(RED)Deleted.$(DEF)"


fclean: clean
	@rm -rf $(NAME)
	@echo "$(SILVER)[$(PURPLR)Library file$(YELLOW) $(notdir $(NAME))$(SILVER)] $(RED)Deleted.$(DEF)"


re: fclean all
