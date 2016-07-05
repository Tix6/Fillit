# ---------------------------------------------------------------------------- #
# PROJECT DATA
# ---------------------------------------------------------------------------- #

NAME		=	fillit

# ---------------------------------------------------------------------------- #

SRCS		=	\
				main.c			\
				input.c			\
				tetriminos.c	\
				square.c		\
				list.c			\
				misc.c			\
				fill.c			\

# ---------------------------------------------------------------------------- #
# PROJECT CONFIGURATION
# ---------------------------------------------------------------------------- #

CFLAGS		=	\
				-g 								\
				-Wall -Wextra -Werror			\

# >>> REQUIRED FOR LIBRARIES >>> THINK ABOUT CHANGING THE *LIBS rules

CPPFLAGS	=	\
				-I $(DIRINC)					\
				-I $(DIRLIB)libft/$(DIRINC)		\

LDFLAGS		=	\
				-L $(DIRLIB)libft				\

LDLIBS		=	\
				-lft							\

# GLOBAL SETUP
AR			=	ar
CC			=	clang
RM			=	rm
MKDIR		=	mkdir
MAKE		=	make

DIRSRC		=	./srcs/
DIROBJ		=	./.objs/
DIRINC		=	./incs/
DIRLIB		=	./libs/

# EXTRA COLOR
C_DFL		=	\033[0m
C_GRA		=	\033[30m
C_RED		=	\033[31m
C_GRE		=	\033[32m
C_YEL		=	\033[33m
C_BLUE		=	\033[34m
C_MAG		=	\033[35m
C_CYA		=	\033[36m
C_WHI		=	\033[37m

# ============================================================================ #

# ---------------------------------------------------------------------------- #
# SOURCES NORMALIZATION
# ---------------------------------------------------------------------------- #

SRC			=	$(addprefix $(DIRSRC), $(SRCS))
OBJ			=	$(addprefix $(DIROBJ), $(notdir $(SRC:.c=.o)))

# ---------------------------------------------------------------------------- #
# RULES
# ---------------------------------------------------------------------------- #

all			:	libs $(NAME)
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) build completed\n" "$(MAKE)"

$(NAME)		:	$(DIROBJ) $(OBJ)
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) linking objects\n" "$(CC)"
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

# ---------------------------------------------------------------------------- #
# CUSTOMISABLE RULES

libs		:
	@make -C $(DIRLIB)libft

fcleanlibs	:
	@make -C $(DIRLIB)libft fclean

norme		:
	@/usr/bin/norminette	\
		$$(find * -name "*.[ch]" ! -path "test/*")

# ---------------------------------------------------------------------------- #

clean		:
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) remove objects\n" "$(RM)"
	@$(RM) -rf $(DIROBJ)

fclean		:	clean fcleanlibs
	@printf "$(C_GRE)[ $(NAME) ] [ %-6s ]$(C_DFL) remove binaries\n" "$(RM)"
	@$(RM) -f $(NAME)

re			:	fclean all

$(DIROBJ)	:
	@$(MKDIR) -p $(DIROBJ)

depend		:
	@sed -e '/^#start/,/^end/d' Makefile > .mftmp && mv .mftmp Makefile
	@printf "#start\n\n" >> Makefile
	@$(foreach s, $(SRC),													\
		printf '$$(DIROBJ)'										>> Makefile	&& \
		printf "$(shell $(CC) -MM $(s) $(CPPFLAGS) | tr '\\' ' ')\n"	>> Makefile	&& \
																			\
		printf '\t\t@$$(CC) -c $(s) -o '						>> Makefile	&& \
		printf '$(addprefix $(DIROBJ), $(notdir $(s:.c=.o))) '	>> Makefile	&& \
		printf '$$(CPPFLAGS) $$(CFLAGS) \n\n'					>> Makefile	|| \
																			\
		(sed -e '/^#start/,$$d' Makefile > .mftmp && mv .mftmp Makefile		&& \
		printf "#start\n\n"										>> Makefile	&& \
		printf "$(C_RED)[ $(NAME) ] [ %-6s ]$(C_DFL) " "dep"				&& \
		printf "$(s) rule generation failed\n"								) \
	;)
	@printf "\n#end\n" >> Makefile

.PHONY	:	 libs test


# ---------------------------------------------------------------------------- #
# AUTO-GENERATED SECTION - do not modify
# ---------------------------------------------------------------------------- #

#start

$(DIROBJ)main.o: srcs/main.c incs/fillit.h libs/libft/./incs/libft.h     libs/libft/./incs/gnl.h
		@$(CC) -c ./srcs/main.c -o ./.objs/main.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)input.o: srcs/input.c incs/fillit.h libs/libft/./incs/libft.h     libs/libft/./incs/gnl.h
		@$(CC) -c ./srcs/input.c -o ./.objs/input.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)tetriminos.o: srcs/tetriminos.c incs/fillit.h libs/libft/./incs/libft.h     libs/libft/./incs/gnl.h
		@$(CC) -c ./srcs/tetriminos.c -o ./.objs/tetriminos.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)square.o: srcs/square.c incs/fillit.h libs/libft/./incs/libft.h     libs/libft/./incs/gnl.h
		@$(CC) -c ./srcs/square.c -o ./.objs/square.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)list.o: srcs/list.c incs/fillit.h libs/libft/./incs/libft.h     libs/libft/./incs/gnl.h
		@$(CC) -c ./srcs/list.c -o ./.objs/list.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)misc.o: srcs/misc.c incs/fillit.h libs/libft/./incs/libft.h     libs/libft/./incs/gnl.h
		@$(CC) -c ./srcs/misc.c -o ./.objs/misc.o $(CPPFLAGS) $(CFLAGS) 

$(DIROBJ)fill.o: srcs/fill.c incs/fillit.h libs/libft/./incs/libft.h     libs/libft/./incs/gnl.h
		@$(CC) -c ./srcs/fill.c -o ./.objs/fill.o $(CPPFLAGS) $(CFLAGS) 


#end
