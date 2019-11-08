CC=gcc -Wall -Wextra -Werror
SRC=filler.c create_step.c delete_step.c track_enemy.c attack_enemy.c
NAME=tlorine.filler
LIB=lib/libft.a
OBJ=filler.o create_step.o delete_step.o track_enemy.o attack_enemy.o
PLAYER=resources/players/tlorine.filler

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) -c $(SRC)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $@;
	mv -f $(NAME) resources/players

clean:
	rm -rf $(OBJ)
fclean: clean $(PLAYER)
	rm -rf $(PLAYER)
re: clean all