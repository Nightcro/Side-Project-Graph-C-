#include "ListaNod.hpp"
#include "ListaEdge.hpp"

class Graf
{
private:
	ListaEdge edges;
	ListaNod nods;
public:
	Graf(){}
	Graf(ListaNod &);
	Graf(ListaEdge &);
	Graf(ListaNod &, ListaEdge &);
	void Add(Nod);
	void Add(int ID1, int ID2);
	Edge* GetEdge(int ID1, int ID2); 
	bool Check(int);
	bool Check(int, int);
	void Remove(int i);
	void Remove(int i, int j) { edges.Remove(i, j); }
	ListaNod* GetNeighbours(int);
	void Print();
	int Get_color(int ID);
	bool Set_color(int i, int color);
	void Clear_color();
	bool IsConnected_BFS(int ID1, int ID2);
	bool IsConnected_DFS(int ID1, int ID2);
	int* Short_dist(int ID);
	static Graf* ReadFromFile(char *s);
};