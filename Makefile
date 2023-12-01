TARGET = lab2

.PHONY: all clean run
all: $(TARGET)

$(TARGET) : main.o funcs.o operations.o converse.o
	gcc main.o funcs.o operations.o converse.o -o $(TARGET)

main.o : main.c
	gcc -c main.c -o main.o

funcs.o : funcs.c
	gcc -c funcs.c -o funcs.o

operations.o : operations.c
	gcc -c operations.c -o operations.o

converse.o : converse.c
	gcc -c converse.c -o converse.o

clean :
	rm $(TARGET) *.o

run : $(TARGET)
	./$(TARGET)

