CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard srcs/*.c)
INCLUDES = -Iincludes
OBJS = $(patsubst srcs/%.c, srcs/%.o, $(SRCS))

TARGET = libft.a

$(TARGET): $(OBJS)
	ar rcs $@ $^

$(OBJS): srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

.PHONY: clean

clean:
	rm $(TARGET)
	rm $(OBJS)
