# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 12:40:44 by amarcell          #+#    #+#              #
#    Updated: 2021/05/13 14:24:19 by amarcell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Reset
COLOR_OFF	="\033[0m"       # Text Reset

# Regular Colors
BLACK		=		"\033[0;30m"        # Black
RED			=		"\033[0;31m"          # Red
GREEN		=		"\033[0;32m"        # Green
YELLOW		=		"\033[0;33m"       # Yellow
BLUE		=		"\033[0;34m"         # Blue
PURPLE		=		"\033[0;35m"       # Purple
CYAN		=		"\033[0;36m"         # Cyan
WHITE		=		"\033[0;37m"        # White

# Bold
BBLACK		=		"\033[1;30m       # Black
BRED		=		"\033[1;31m         # Red
BGREEN		=		"\033[1;32m"       # Green
BYELLOW		=		"\033[1;33m"      # Yellow
BBLUE		=		"\033[1;34m"        # Blue
BPURPLE		=		"\033[1;35m"      # Purple
BCYAN		=		"\033[1;36m"        # Cyan
BWHITE		=		"\033[1;37m"       # White

# Underline
UBLACK		=		"\033[4;30m"       # Black
URED		=		"\033[4;31m"         # Red
UGREEN		=		"\033[4;32m"       # Green
UYELLOW		=		"\033[4;33m"      # Yellow
UBLUE		=		"\033[4;34m"        # Blue
UPURPLE		=		"\033[4;35m"      # Purple
UCYAN		=		"\033[4;36m"        # Cyan
UWHITE		=		"\033[4;37m"       # White




#---------------------SRCS---------------------#
LIBFT_DIR	=		../libft

CMD_DIR		=		../command

OBJS_DIR	=		objs

LIBFT		=		libft.a

CMD			=		commands.a

SRCS		=		checker_bonus.c		utils_bonus.c	\
					mat_free_bonus.c	init_bonus.c	
				
#---------------------COMPILER---------------------#

NAME		=		checker

CC 			= 		@ gcc 

CFLAGS		=		-Wall -Wextra -Werror

OBJS		=		$(patsubst %.c, ${OBJS_DIR}/%.o, ${SRCS})

$(OBJS_DIR)/%.o :	./%.c
			@ mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@


#---------------------COMMANDS---------------------#

all:		$(NAME)

$(NAME):    $(OBJS)
			@ make -C $(LIBFT_DIR)
			@ make -C $(CMD_DIR)
			@ cp  $(LIBFT_DIR)/$(LIBFT) .
			@ cp  $(CMD_DIR)/$(CMD) .
			 $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(CMD) -o $(NAME)
			@ echo $(BGREEN) "$(NAME) compiled successfully ✅" $(COLOR_OFF)

clean:
			@ rm -f $(OBJS)
			@ echo $(BWHITE) "$(NAME) .o files are successfull deleted 📃➡ 🗑" $(COLOR_OFF)

fclean:		clean
			@ rm -rf $(OBJS_DIR)
			@ rm -f $(NAME) $(LIBFT)  $(CMD) 
			@ echo $(BWHITE) "$(NAME) library file is successfull deleted 🗂 ➡🗑" $(COLOR_OFF)

re:			fclean
			@ make -C $(CMD_DIR) re
			@ make -C $(LIBFT_DIR) re
			@ make all
			@ echo $(BGREEN) "$(NAME) recompiled successfully ♻️ ✅" $(COLOR_OFF)

#---------------------RUN---------------------#

run:		re
			@ clear
			@ echo $(BBLUE) "-----|RUNNING 🖥 $(NAME)|-----" $(COLOR_OFF) $(CYAN)
			@ ./$(NAME) 1 2 3

#---------------------NORME---------------------#

norme:
			@ echo $(BPURPLE) "-------|norme $(NAME)|-------" $(COLOR_OFF) $(PURPLE)
			@ norminette $(SRCS)
			@ norminette *.h
			@ echo $(COLOR_OFF)

.PHONY: 	all clean fclean re run d norme screenshot debug bonus