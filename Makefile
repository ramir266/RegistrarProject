BUILD_FLAGS = -W -Wall -pedantic 
CC = g++
RM = rm
OUT = *.out *.o

all: a.out

Customer.o: Makefile Customer.cpp
	$(CC) $(BUILD_FLAGS) -c Customer.cpp -o Customer.o

ControllingInput.o: Makefile ControllingInput.cpp
	$(CC) $(BUILD_FLAGS) -c ControllingInput.cpp -o ControllingInput.o

RunFile.o: Makefile RunFile.cpp
	$(CC) $(BUILD_FLAGS) -c RunFile.cpp -o RunFile.o

a.out: Makefile ControllingInput.o Customer.o RunFile.o main.cpp
	$(CC) $(BUILD_FLAGS) ControllingInput.o Customer.o RunFile.o main.cpp -o a.out

clean:
	$(RM) $(OUT)
