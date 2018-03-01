#include "Stiva.hpp"

Stiva::Stiva()
{
	root = NULL;
}

Stiva::~Stiva()
{
	while(root != NULL)
	{
		lista *aux = root;
		root = root->leg;
		delete aux;
	}
}

bool Stiva::IsEmpty()
{
	return root == NULL;
}

void Stiva::Push(Nod &i)
{
	lista *aux = new lista(i);
	aux->leg = root;
	root = aux;
}

Nod Stiva::Pop()
{
	if(IsEmpty())
	{
		Nod n(-1);
		return n;
	}
	lista *aux = root;
	Nod n = aux->ln;
	root = root->leg;
	delete aux;
	return n;
}

Nod Stiva::Peek()
{
	if(IsEmpty())
	{
		Nod n(-1);
		return n;
	}
	return root->ln;
}