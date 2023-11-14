OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
Stack.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
