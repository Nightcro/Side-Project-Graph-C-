#include "Nod.hpp"
/*
Nod::Nod(Nod &ln)
{
	ID = ln.GetID();
	color = ln.GetColor();
}
*/ 
void Nod::operator=(Nod &n)
{ 
	ID = n.GetID(); 
	color = n.GetColor();
}

void Nod::operator=(Nod n)
{ 
	ID = n.GetID(); 
	color = n.GetColor();
}