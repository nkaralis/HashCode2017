OBJS    = main.o
SOURCE  = main.cpp
HEADER  = 
OUT     = pizza
CC      = g++
FLAGS   = -g -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

clean:
	rm -f $(OBJS) $(OUT)
