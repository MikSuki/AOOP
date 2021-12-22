all: main.out

main.out: Trace.o  Vector.o main.o
	g++ Trace.o  Vector.o  main.o -o main.out

Trace.o: Trace.cpp Trace.h
	g++ -c Trace.cpp -o Trace.o

Vector.o: Vector.cpp Vector.h
	g++ -c Vector.cpp -o Vector.o

main.o: main.cpp Vector.h Trace.h
	g++ -c main.cpp -o main.o

clean:
	rm -f *.out
	rm -f *.o
