CC = gcc
SRCS = %.c
OBJS = main.o P2.o P1.o util.o
CFLAGS = -I ../the_headers

all: main clean

main: $(OBJS)
		$(CC) $(OBJS) -o $@ -lm

%.o: %.c
		$(CC) -o $@ -c $< $(CFLAGS) $(DEFINE)

clean :
		-rm -f *.o *~