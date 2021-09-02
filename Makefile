NAME		= push_swap

HEADER		= ./srcs/push_swap.h

SRCS_DIR	= ./srcs
SRCS_NAME	= push_swap.c			\
			  push_swap_utils.c		\
			  action_utils.c		\
			  action_utils_push.c	\
			  actions.c				\
			  add_index.c			\
			  create_stack.c		\
			  create_stack_check.c	\
			  solve.c				\
			  solve_utils_1.c		\
			  solve_utils_2.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf

all :		$(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME) $(OBJS)

re :		fclean all

.PHONY :	all clean fclean re
