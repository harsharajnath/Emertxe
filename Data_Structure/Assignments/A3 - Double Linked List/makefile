OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
DLList.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
