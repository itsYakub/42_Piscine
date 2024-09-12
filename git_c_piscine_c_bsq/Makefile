CC = cc
CFLAGS = \
	-Wall -Wextra -Werror \
	-g

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
IFLAGS = -Iinclude

TARGET = bsq.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(IFLAGS)

.PHONY: re fclean clean

re: \
	fclean \
	all

fclean:	\
	clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)
