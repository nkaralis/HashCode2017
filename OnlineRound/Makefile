OBJS    = main.o
SOURCE  = main.c
HEADER  = 
OUT     = distribution
CC      = gcc
FLAGS   = -g -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

main.o: main.c
	$(CC) $(FLAGS) main.c

clean:
	rm -f $(OBJS) $(OUT)
