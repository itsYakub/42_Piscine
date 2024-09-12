CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
INCLUDES = -Iincludes
OBJS = $(patsubst srcs/%.c, srcs/%.o, $(SRCS))

TARGET = libft.a

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $@ $^

$(OBJS): srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

.PHONY: re fclean clean

re: fclean all

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)
