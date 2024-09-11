CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -static-libgcc

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

TARGET = ft_cat

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
