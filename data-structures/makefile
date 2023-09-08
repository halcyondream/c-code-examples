OBJECTS = data.o linkedlist.o queue.o stack.o tree.o
BINARY = demo

demo: $(OBJECTS)
	gcc demo.c -o $(BINARY) $(OBJECTS)
	chmod +x $(BINARY)
	rm *.o
	./$(BINARY)

data: data.c
	gcc -c data.c -o data.o

linkedlist: linkedlist.c 
	gcc -c linkedlist.c -o linkedlist.o

queue: queue.c
	gcc -c queue.c -o queue.o

stack: stack.c
	gcc -c stack.c -o stack.o

tree: tree.c 
	gcc -c tree.c -o tree.o

clean:
	rm *.o 
	rm $(BINARY)
