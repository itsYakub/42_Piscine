CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

TARGET = ft_display_file

all: ${TARGET}

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: fclean clean

fclean:
	rm $(TARGET)

clean:
	rm $(OBJS)
