CC = clang
CFLAGS = -Wall -Wextra -O3
PROG = dancing_I
LIBS = -lm -lGL -lGLU -lglut

SRCS = main.c

all : $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS) 

clean:
	rm -f $(PROG)
