OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
BSearch.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
