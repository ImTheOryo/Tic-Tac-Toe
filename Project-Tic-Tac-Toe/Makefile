NAME = tictactoe

# Fichiers source (.c)
SRCS = main.c

# Fichiers objets (.o)
OBJS = $(SRCS:.c=.o)

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Règle par défaut : construire le programme
all: $(NAME)

# Compilation du programme
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

# Compilation des fichiers objets
%.o: %.c tic-tac-toe.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers compilés
fclean:
	rm -f $(OBJS) $(NAME)

# Nettoyer et recompiler
re: fclean all
