CC := gcc
SRCS:= $(wildcard api/*.c) $(wildcard api/data/*.c) $(wildcard api/pages/*.c) main.c
OBJS := $(SRCS:.c=.o)
OUTPUT := main

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUTPUT)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUTPUT)
