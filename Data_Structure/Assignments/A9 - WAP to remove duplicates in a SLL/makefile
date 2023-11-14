OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
SLList.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
