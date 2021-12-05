all: mytar.o 
	g++ main.cpp mytar.o -o main.out

mytar.o:
	g++ -c mytar.cpp  -o mytar.o

clean:
	rm -f main.out
	rm -f mytar.o
