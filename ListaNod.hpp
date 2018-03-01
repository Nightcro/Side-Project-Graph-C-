#include "Nod.hpp"
#include <iostream>

class ListaNod
{
private:
	class lista
	{
	public:
		Nod ln;
		lista* leg;
	public:
		lista(Nod &n, lista *l = NULL)
			: ln(n), leg(l){}
	};
	lista *root;
public:
	ListaNod(){root = NULL;}
	~ListaNod();
	void AddNod(Nod &ln);
	void Remove(int i);
	void Print();
	int Size();
	Nod* Getn_nod(int i);
	Nod* Get_nod(int ID);
	void operator=(ListaNod &);
};