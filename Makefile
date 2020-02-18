OBJS   = MyHw0.o
SOURCE = MyHw0.cpp
OUT    = MyHw0
CC     = g++
FLAGS  = -c

all:  $(OBJS)
	$(CC)  -o $(OUT)  $(OBJS)

MyHw0.o: MyHw0.cpp
	$(CC) -std=c++0x $(FLAGS) MyHw0.cpp