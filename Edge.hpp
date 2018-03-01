#include "Nod.hpp"

class Edge
{
private:
	Nod *first, *second;
	int Cost;
public:
	Edge(Nod* f, Nod* s)
		: first(f), second(s), Cost(0){}
	Edge(Nod* f, Nod* s, int c)
		: first(f), second(s), Cost(c){}
	Edge(Edge &n);
	//~Edge();
	Nod* Get_first(){return first;}
	Nod* Get_second(){return second;}
	void SetCost(int i){ Cost = i; }
	int GetCost(){ return Cost; }
};
