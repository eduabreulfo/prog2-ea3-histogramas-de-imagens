
OBJS	= main.o image.o histogram.o
SOURCE	= main.c src/image.c src/histogram.c
HEADER	= headers/image.h headers/histogram.h
OUT	= main
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm
# -g option enables debugging mode 
# -c flag generates object code for separate files


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)


# create/compile the individual files >>separately<<
main.o: main.c
	$(CC) $(FLAGS) main.c 

image.o: src/image.c
	$(CC) $(FLAGS) src/image.c 

histogram.o: src/histogram.c
	$(CC) $(FLAGS) src/histogram.c 


# clean house
clean:
	rm -f $(OBJS) $(OUT)

# run the program
run: $(OUT)
	./$(OUT)