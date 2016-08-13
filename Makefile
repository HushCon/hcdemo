APP=hcdemo
CFLAGS=-g3 -Wall
CC=gcc
OBJS=main.o
LDFLAGS=-lcurses

all: $(OBJS) $(APP)

$(APP): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS) $(APP)
