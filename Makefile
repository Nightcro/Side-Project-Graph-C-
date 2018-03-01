
build: Graf.o Coada.o Stiva.o
	g++ -std=c++11 -Wall main.cpp Graf.o ListaNod.o ListaEdge.o Nod.o Edge.o Coada.o Stiva.o -o main

Graf.o: ListaNod.o ListaEdge.o
	g++ -std=c++11 -c Graf.cpp -o Graf.o

ListaNod.o: Nod.o
	g++ -c ListaNod.cpp -o ListaNod.o

ListaEdge.o: Edge.o
	g++ -c ListaEdge.cpp -o ListaEdge.o

Nod.o:
	g++ -c Nod.cpp -o Nod.o

Edge.o: Nod.o
	g++ -c Edge.cpp -o Edge.o

Coada.o: Nod.o
	g++ -c Coada.cpp -o Coada.o

Stiva.o: Nod.o
	g++ -c Stiva.cpp -o Stiva.o

clean:
	rm -rf main
	rm -rf *.o