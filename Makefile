NAME := ft_ls

SRC := ft_ls.c

SRCDIR := ./srcs

OBJDIR := objs

HEADER := -I libft

LIBFTDIR := ./libft

OBJS := $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC := gcc

CFLAGS := -Wall -Werror -Wextra -c -g

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(NAME): OBJS
		$(CC) $(OBJS) -o $(NAME) $(HEADER) -L $(LIBFTDIR) -lft

OBJS: LIB
		mkdir $(OBJDIR)
		$(CC) $(CFLAGS) $(SRC) $(HEADER) 
		mv *.o $(OBJDIR)

LIB:
	make -C $(LIBFTDIR)
	rm -rf $(OBJDIR)

clean:
	make -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
		make -C $(LIBFTDIR) fclean
		rm -f $(NAME)

re: fclean all

