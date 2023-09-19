# S = src/
# O = obj/
# I = inc/
# SRC = $(S)main.c
# OBJ = $(SRC:$(S)%=$(O)%.o)
# CC = gcc
# CFLAGS = -Wall -Werror -Wextra -I $I
# RM = rm -f
# RMDIR = rm -rf
# NAME = push_swap

# $(O):
# 	@mkdir -p $@

# all: $(NAME)

# $(OBJ): | $(O)

# $(O)%.o: $(S)%
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -o $@

# cleanobj:
# 	$(RM) $(wildcard $(OBJ))

# cleanobjdir: cleanobj
# 	$(RMDIR) $(O)

# clean: cleanobjdir

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
S = src/
O = obj/
I = inc/
SRC = $(wildcard $(S)*.c)
OBJ = $(patsubst $(S)%.c,$(O)%.o,$(SRC))
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(I)
RM = rm -f
RMDIR = rm -rf
NAME = push_swap

$(O):
	@mkdir -p $@

all: $(NAME)

$(OBJ): | $(O)

$(O)%.o: $(S)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

cleanobj:
	$(RM) $(wildcard $(O)*.o)

cleanobjdir: cleanobj
	$(RMDIR) $(O)

clean: cleanobjdir

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
