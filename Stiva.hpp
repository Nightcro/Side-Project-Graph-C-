#include <iostream>
#include "Nod.hpp"

class Stiva
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
	Stiva();
	~Stiva();
	bool IsEmpty();
	void Push(Nod &);
	Nod Pop();
	Nod Peek();
};