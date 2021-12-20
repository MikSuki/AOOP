all: main.out

main.out: Form.o main.o
	g++ Form.o main.o -o main.out

Form.o: Form.cpp Form.h
	g++ -c Form.cpp -o Form.o

main.o: main.cpp Form.h
	g++ -c main.cpp -o main.o

clean:
	rm -f *.out
	rm -f *.o
