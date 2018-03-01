#include <iostream>
#include "Nod.hpp"

class Coada
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
	lista *head, *tail;
public:
	Coada();
	~Coada();
	void Push(Nod &);
	Nod Pop();
	Nod Peek();
	bool IsEmpty();
	void Print();
};