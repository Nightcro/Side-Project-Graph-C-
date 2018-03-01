#include "Edge.hpp"
#include <iostream>

class ListaEdge
{
private:
	class lista
	{
	public:
		Edge edg;
		lista* leg;
	public:
		lista(Edge& e, lista *l = NULL)
			: edg(e), leg(l){}
	};
	lista *root;
public:
	ListaEdge(){root = NULL;}
	~ListaEdge();
	void AddEdge(Edge edg);
	void Remove(int first, int second);
	void Print();
	Edge* Get_edge(int i);
	int Size();
	void operator=(ListaEdge &);
};