# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 14:42:46 by amarcell          #+#    #+#              #
#    Updated: 2021/04/30 17:18:22 by amarcell         ###   ########.fr        #
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

OBJS_DIR	=		objs

SRCS		= 		ft_isprint.c			ft_memcmp.c			ft_putchar_fd.c		ft_freejoin.c		\
					ft_split.c				ft_strlcat.c		ft_strncmp.c		ft_substr.c			\
					ft_atoi.c				ft_isalpha.c		ft_itoa.c			ft_memcpy.c			\
					ft_putendl_fd.c			ft_strchr.c			ft_strlcpy.c		ft_strnstr.c		\
					ft_tolower.c			ft_bzero.c   		ft_isascii.c		ft_memccpy.c		\
					ft_memmove.c			ft_putnbr_fd.c 		ft_strdup.c 		ft_strlen.c			\
					ft_strrchr.c			ft_toupper.c		ft_calloc.c			ft_isdigit.c		\
					ft_memchr.c				ft_memset.c			ft_putstr_fd.c		ft_strjoin.c		\
					ft_strmapi.c			ft_strtrim.c		ft_lstnew.c			ft_strdigit.c		\
					ft_lstadd_front.c		ft_lstsize.c		ft_lstlast.c		ft_lstadd_back.c	\
					ft_lstdelone.c 			ft_lstclear.c		ft_lstiter.c		ft_lstmap.c			\
					ft_isalnum.c			get_next_line.c		ft_swap.c
					
				
#---------------------COMPILER---------------------#

NAME		=		libft.a

CC 			= 		@ gcc

CFLAGS		=		-Wall -Wextra -Werror 

OBJS		=		$(patsubst %.c, ${OBJS_DIR}/%.o, ${SRCS})

$(OBJS_DIR)/%.o :	./%.c
			@ mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

#---------------------COMMANDS---------------------#

all:		$(NAME)

$(NAME):	$(OBJS)
			@ ar rcs $(NAME) $(OBJS) libft.h
			@ echo $(BGREEN) "$(NAME) compiled successfully ✅" $(COLOR_OFF)

clean:
			@ rm -f $(OBJS)
			@ echo $(BWHITE) "$(NAME) .o files are successfull deleted 📃➡ 🗑" $(COLOR_OFF)

fclean:		clean
			@ rm -rf $(OBJS_DIR)
			@ rm -f $(NAME)
			@ echo $(BWHITE) "$(NAME) file is successfull deleted 🗂 ➡🗑" $(COLOR_OFF)

re:			fclean all
			@ echo $(BGREEN) "$(NAME) recompiled successfully ♻️ ✅" $(COLOR_OFF)

norme:
			@ echo $(BBLUE) "-------|norme $(NAME)|-------" $(COLOR_OFF) $(BLUE)
			@ norminette $(SRCS)
			@ norminette *.h
			@ echo $(COLOR_OFF)

.PHONY: 	all clean fclean re norme 