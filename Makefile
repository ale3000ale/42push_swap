# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 13:12:04 by amarcell          #+#    #+#              #
#    Updated: 2021/11/19 18:45:28 by amarcell         ###   ########.fr        #
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
BBLACK		=		"\033[1;30m			# Black
BRED		=		"\033[1;31m			# Red
BGREEN		=		"\033[1;32m"		# Green
BYELLOW		=		"\033[1;33m"		# Yellow
BBLUE		=		"\033[1;34m"		# Blue
BPURPLE		=		"\033[1;35m"		# Purple
BCYAN		=		"\033[1;36m"		# Cyan
BWHITE		=		"\033[1;37m"		# White

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


CMD_DIR		=		command

LIBFT_DIR	=		libft

PROGRAM_DIR	=		program

CHEKER_DIR	=		checker

PUSH_SWAP_DIR=		push_swap

CHEKER		=		checker

PUSH_SWAP	=		push_swap

TEST		=		test.sh

NUM			=	     447  246  113   64  368  117  452   28   26  377  220  252   84  116  357  414  254  209   48  129  264  474  136  258   40  238  175  462  179   73  496  139  208  416  217   63  286  453  341  182  222  347  124  386   38  319   37  458  345  373   25   59  145  404   18  400  273  240  344  401  267  352   14   51  322  160  370  409  263  494  289  305  378  178   20  336  308  193  183  276  105  287  223   10  361   67   22  382  332  155  280  216  337  100  110   50  198   70   45  323  213  365  137  480  376  256  102   71   23  371    4  364  275  146  411   61  266  247  125   29  128  302  144  161  430  152  232  471  104  151  173   72   85  485   98  153  369  202  185  413  459  138  315  314  260   36  177   52  237  441  443  235  312    7  301  448  149  230  199  162  176    3  249  338   80  466  349   76  304  490   90  306   58   55  142  131  224  444  495  339   15  170  148   77  397  375   74   65  425  194  291  274  268  115   42  497  406  454   16   83  384  172  214  380  253  188  475   68   93  101  204  407   89  234  388  196  385  473  226  281  335   11  418  207    2  432  141   78  374  211    6  395  343  283  243  225  328  342  468  231  403  167  316  329   24  410   44  265  270  111  327  412   13  408   35  350   32  492  440  285  127  438  455  205  106  429  262  197  298  451  422  261   81   62  215    9  278  310  467  288  351  353   49  132  192  465  135  133  488  229  143  294  309  428  354  463  415   17  121  499  210  366  227  219  187  245   75  242   33  392  489  120  228  398   69  460  419   97  206  481   91   53  296  476  478  250  147  320  317   99   87   21  469   54  334   27  168  381  445    5  114  479  150  433  181  255  424  391  461  333  399  500  292  233  420  200  491  464  318  437  434  108  362  257  372  140   41   31  156   47  321  484  493  457  311  212  356  112  190   34  405  164  123  269  435  456  393  109   88   92  166  426  417  107  241  363  326  449  236  282  330  446  203  180  186  271  300  421  134  174  158  189   19  184  436  169  431  358  331  297  165  472  359  299  279  389   30  290   39  171  379  154  470   96  313  251  346  303  360  244   95  477  324  396  122  340   12  277  355  487  325  390  272   46  119    1  498  157  195  159   66   94  293   43  383  439  295  482  450  284  218  126  239  103  483    8  163  387  191   86  307  486  201  427  394  442   79   82  221   57   60  402  423  130  248  348  259  367   56  118  

#---------------------COMPILER---------------------#

NAME		=		tester

CC 			= 		@ gcc 

CFLAGS		=		-Wall -Wextra -Werror

#---------------------COMMANDS---------------------#

all:		$(NAME)

$(NAME):    
			@ make -C $(PUSH_SWAP_DIR)
			@ mkdir -p $(PROGRAM_DIR)
			@ cp  $(TEST) $(PROGRAM_DIR)
			@ cp  $(PUSH_SWAP_DIR)/$(PUSH_SWAP) $(PROGRAM_DIR)/.
			@ echo $(BGREEN) "$(NAME) READY ✅" $(COLOR_OFF)

bonus:
			@ make -C $(CHEKER_DIR)
			@ make -C $(PUSH_SWAP_DIR)
			@ mkdir -p $(PROGRAM_DIR)
			@ cp  $(CHEKER_DIR)/$(CHEKER) $(PROGRAM_DIR)/.
			@ cp  $(TEST) $(PROGRAM_DIR)
			@ cp  $(PUSH_SWAP_DIR)/$(PUSH_SWAP) $(PROGRAM_DIR)/.
			@ echo $(BGREEN) "$(NAME) READY ✅" $(COLOR_OFF)

clean:
			@ make -C $(CHEKER_DIR) clean
			@ make -C $(PUSH_SWAP_DIR) clean
			@ make -C $(LIBFT_DIR) clean
			@ make -C $(CMD_DIR) clean
			@ echo $(BWHITE) ".o files are successfull deleted 📃➡ 🗑" $(COLOR_OFF)

fclean:		clean
			@ make -C $(CHEKER_DIR) fclean
			@ make -C $(PUSH_SWAP_DIR) fclean
			@ make -C $(LIBFT_DIR) fclean
			@ make -C $(CMD_DIR) fclean
			@ rm -rf $(PROGRAM_DIR)
			@ echo $(BWHITE) "$(NAME) successfull deleted 🗂 ➡🗑" $(COLOR_OFF)

re:			fclean
			@ make all
			@ echo $(BGREEN) "$(NAME) recompiled successfully ♻️ ✅" $(COLOR_OFF)

#---------------------RUN---------------------#

run:		bonus
			@ clear
			@ echo $(BBLUE) "-----|RUNNING 🖥 $(NAME)|-----" $(COLOR_OFF) $(CYAN)
			@ $(PROGRAM_DIR)/$(PUSH_SWAP) $(NUM) | $(PROGRAM_DIR)/$(CHEKER) $(NUM)
			@ echo $(COLOR_OFF)

run_view:	bonus
			@ clear
			@ echo $(BBLUE) "-----|RUNNING 🖥 $(NAME)|-----" $(COLOR_OFF) $(CYAN)
			@ $(PROGRAM_DIR)/$(PUSH_SWAP) $(NUM) | $(PROGRAM_DIR)/$(CHEKER) -v $(NUM)
			@ echo $(COLOR_OFF)

run_mac:	all
			@ clear
			@ echo $(BBLUE) "-----|RUNNING 🖥 $(NAME)|-----" $(COLOR_OFF) $(CYAN)
			@ $(PROGRAM_DIR)/$(PUSH_SWAP) $(NUM) | ./checker_Mac $(NUM)
			@ echo $(COLOR_OFF)

run_push:	all
			@ clear
			@ echo $(BBLUE) "-----|RUNNING 🖥 $(PUSH_SWAP)|-----" $(COLOR_OFF) $(GREEN)
			@ $(PROGRAM_DIR)/$(PUSH_SWAP) $(NUM)
			@ echo $(COLOR_OFF)

run_checker:	bonus
			@ clear
			@ echo $(BBLUE) "-----|RUNNING 🖥 $(CHEKER)|-----" $(COLOR_OFF) $(GREEN)
			@ $(PROGRAM_DIR)/$(CHEKER) $(NUM)
			@ echo $(COLOR_OFF)
			
#---------------------NORME---------------------#

norme:
			@- make -C $(CHEKER_DIR) norme
			@- make -C $(PUSH_SWAP_DIR) norme
			@- make -C $(CMD_DIR) norme
			@- make -C $(LIBFT_DIR) norme

.PHONY: 	all clean fclean re run d norme screenshot bonus run_checker run_push run_view