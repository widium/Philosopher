# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:56:37 by ebennace          #+#    #+#              #
#    Updated: 2022/10/25 07:29:00 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# === File && Header === #
SRCS		= 	main.c \
				source/data_struct/chained.c \
				source/data_struct/free_all.c \
				source/env/dining.c \
				source/env/get.c \
				source/env/time.c \
				source/env/convert_time.c \
				source/env/utils_libft.c \
				source/execution/execution.c \
				source/execution/supervisor.c \
				source/init/create.c \
				source/init/init.c \
				source/init/generate.c \
				source/is/can.c \
				source/is/is_env.c \
				source/is/is_philo.c \
				source/parsing/check_parsing.c \
				source/state/philo_state.c \
				source/state/fork.c \
				source/state/eat.c \
				source/verbose/verbose_philo.c \
				source/verbose/verbose_env.c \
				source/verbose/verbose_state.c \
				
# ==== Template ==== #
TEMPLATE = source/header/header.txt

# ==== Execute ==== #
EXE = @./$(NAME)

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
FLAGS 			+= -pthread
MAKE			= make -s


# === Convert all .c to .o with flags === # 
%.o : %.c
			@$(CC) $(FLAGS) -c $< -o $@
	
$(NAME) : 	    $(OBJS)
				@echo "==== Create all .o ===="
				@echo "==== Compiling all .c ===="
				@echo "==== Compiling Philosopher ===="
				@$(CC) $(OBJS) $(FLAGS) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"		

all : 	 $(NAME)

clean :
				@echo "==== Remove all Philosopher .o ===="
				@$(RM_FILE) $(OBJS)

fclean : clean
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