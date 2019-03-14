# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 13:13:35 by ygarrot           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2019/03/14 14:34:05 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME) all clean fclean re

NAME = ft_ping

FLAGS = -Wall -Werror -Wextra
FLAGS += -g3
# FLAGS += -fsanitize=address,undefined
SRC_DIR = src

INCLUDE =  includes/

OBJ_DIR = obj

SRC =\
	 fill_ip.c\
	 ip_version.c\
	 main.c\
	 ping.c\
	 set_socket.c\
	 socket_creation.c\
	 time.c
	 #print.c\

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC))))

OBJ_FILES = $(sort $(dir $(OBJS) $(dir $SHARED_OBJS)))

LIBFT = libft/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/$(NAME).h
	@gcc $(FLAGS) -o $@ -c $<  -I $(INCLUDE)


$(NAME): obj_dir $(OBJS)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(OBJS)  -I $(INCLUDE) -L libft -l ft
	@echo $(NAME) is compiled

obj_dir:
	@mkdir -p $(OBJ_DIR) || true

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
PHONY: $(NAME) all clean fclean re
=======
#    Updated: 2019/03/09 15:55:03 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm 

FLAGS = -Wall -Werror -Wextra

SRC_FOLDER = src/
INCLUDE =  includes/\

OBJ_DIR = mkdir obj
SRC_FP =\
	main.c

OBJ = $(addprefix $(SRC_FOLDER), $(SRC_FP:.c=.o))
LIBFT = ../libft/libft.a

all: $(NAME)

src/%.o: src/%.c includes/ft_ping.h
	gcc $(FLAGS) -o $@ -c $<  -I $(INCLUDE)

$(NAME): $(OBJ)
	@make -C ../libft -j
	gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INCLUDE) -L ../libft -l ft

clean:
	@rm -f $(OBJ)
	@make -C ../libft clean

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f $(NAME_NO_HOST)
	@make -C ../libft fclean

re: fclean all

.PHONY: $(NAME) all clean fclean re
>>>>>>> 481ff8ddf501b92bad1b4a18c1ccd2425b20ff35
