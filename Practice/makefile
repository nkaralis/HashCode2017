OBJS    = main.o
SOURCE  = main.cpp
HEADER  = 
OUT     = pizza
CC      = g++
FLAGS   = -g -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) -L. -loracle_v3 -lhash -lpthread

main.o: main.c
	$(CC) $(FLAGS) main.c

functions.o: functions.c
	$(CC) $(FLAGS) functions.c

clean:
	rm -f $(OBJS) $(OUT)
