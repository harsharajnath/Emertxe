OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
Tree.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
