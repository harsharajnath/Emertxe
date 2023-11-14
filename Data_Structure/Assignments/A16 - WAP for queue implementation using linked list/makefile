OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
Queue.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
