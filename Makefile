# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:56:37 by ebennace          #+#    #+#              #
#    Updated: 2022/10/11 12:00:07 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

# === File && Header === #
SRCS		= 	main.c \
				source/init/init.c \
				source/verbose/verbose_philo.c \
				source/verbose/verbose_env.c \
				source/parsing/check_parsing.c \
				source/data_struct/chained.c \

# ==== Template ==== #
TEMPLATE = source/header/header.txt

# ==== Execute ==== #
EXE = @./$(NAME)
LIBFT = source/libft/libft.a

# ==== Debug && Leak ==== #
SANITIZE 		= -fsanitize=address
LEAKS 			= -fsanitize=leak
DEBUGGER		= lldb

# ==== Remove ==== #
RM_FILE = /bin/rm -rf

# ==== Objet && compiling ==== #
OBJS			= $(SRCS:.c=.o)
CC				= gcc
FLAGS			= -g3
FLAGS 			+= -Wall -Werror -Wextra
FLAGS 			+= $(SANITIZE)
MAKE			= make -s


# === Convert all .c to .o with flags === # 
%.o : %.c
			@$(CC) $(FLAGS) -c $< -o $@
	
$(NAME) : 	    $(OBJS)
				@echo "==== Create all .o ===="
				@echo "==== Compiling all .c ===="
				@echo "==== Compiling libft ===="
				@$(MAKE) -C source/libft
				@echo "==== Compiling Philosopher ===="
				@$(CC) $(OBJS) $(FLAGS) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"		

all : 	 $(NAME)

clean :
				@echo "==== Remove all Libft .o ===="
				@$(MAKE) clean -C source/libft
				@echo "==== Remove all Philosopher .o ===="
				@$(RM_FILE) $(OBJS)

fclean : clean
				@$(MAKE) fclean -C source/libft
				@$(RM_FILE) $(NAME)

debug : 		$(OBJS)
				@echo "==== Mode Debug Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(SANITIZE) $(LIBFT) -o $(NAME)
				$(DEBUGGER) $(NAME)
				@cat "$(TEMPLATE)"
				
sanitize :		$(OBJS)
				@echo "==== Mode Sanitize Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(SANITIZE) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"

leak :			$(OBJS)
				@echo "==== Mode Leak Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(LEAKS) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"


re : fclean all
.PHONY			: all clean fclean re leak sanitize