OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
InvertedSearch.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
