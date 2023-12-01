TARGET = lab2

.PHONY: all clean run
all: $(TARGET)

$(TARGET) : main.o funcs.o
	gcc main.o funcs.o -o $(TARGET)

main.o : main.c
	gcc -c main.c -o main.o

funcs.o : funcs.c
	gcc -c funcs.c -o funcs.o

clean :
	rm $(TARGET) *.o

run : $(TARGET)
	./$(TARGET)

