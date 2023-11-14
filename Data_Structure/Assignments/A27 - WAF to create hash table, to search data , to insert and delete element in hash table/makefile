OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
Hashing.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
