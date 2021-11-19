# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 12:34:16 by amarcell          #+#    #+#              #
#    Updated: 2021/05/11 16:21:18 by amarcell         ###   ########.fr        #
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

OBJS_DIR	=		objs

LIBFT		=		libft.a

SRCS		=		command.c	command2.c	command3.c	utils.c
				
#---------------------COMPILER---------------------#

NAME		=		commands.a

CC 			= 		 @ gcc 

CFLAGS		=		-Wall -Wextra -Werror

OBJS		=		$(patsubst %.c, ${OBJS_DIR}/%.o, ${SRCS})

$(OBJS_DIR)/%.o :	./%.c
			@ mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

#---------------------COMMANDS---------------------#

all:		$(NAME)

$(NAME):	$(OBJS)
			@ make -C $(LIBFT_DIR)
			@ cp $(LIBFT_DIR)/$(LIBFT) .
			@ ar rcs $(NAME) $(OBJS)
			@ echo $(BGREEN) "$(NAME) library created successfully ✅" $(COLOR_OFF)

clean:
			@ rm -f $(OBJS)
			@ echo $(BWHITE) "$(NAME) .o compiled files are successfull deleted 📃➡ 🗑" $(COLOR_OFF)

fclean:		clean
			@ rm -rf $(OBJS_DIR)
			@ rm -f $(NAME) $(LIBFT)
			@ echo $(BWHITE) "$(NAME) library file is successfull deleted 🗂 ➡🗑" $(COLOR_OFF)

re:			fclean
			@ make -C $(LIBFT_DIR) fclean
			@ make all
			@ echo $(BGREEN) "$(NAME) recompiled successfully ♻️ ✅" $(COLOR_OFF)


#---------------------NORME---------------------#

norme:
			@ echo $(BGREEN) "-------|norme $(NAME)|-------" $(COLOR_OFF) $(GREEN)
			@ -norminette $(SRCS)
			@ -norminette *.h
			@ echo $(COLOR_OFF)

.PHONY: 	all clean fclean re norme screenshot debug bonus 