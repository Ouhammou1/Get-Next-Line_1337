CC=cc
NAME =get_next_line.a
CFLAGS= -Wall -Wextra -Werror #-fsanitize=address -g  
CFILES= get_next_line.c   get_next_line_utils.c 

bonus= get_next_line_bonus.c   get_next_line_utils_bonus.c 

object = $(CFILES:.c=.o)
bnus = $(bonus:.c=.o)


all: $(NAME) 

bonus:$(bnus)
	ar rcs $(NAME) $(bnus)

$(NAME):$(object)
	ar rcs $(NAME) $(object)


clean:
	rm -f $(object) $(bnus)

fclean: clean
	rm -f $(NAME) 

re: fclean $(NAME)