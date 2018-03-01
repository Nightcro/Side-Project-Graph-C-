#include "Coada.hpp"

Coada::Coada()
{
	head = NULL;
	tail = NULL;
}

Coada::~Coada()
{
	while(head != NULL)
	{
		lista *aux = head;
		head = head->leg;
		delete aux;
	}
}

bool Coada::IsEmpty()
{
	return ((head == NULL) && (tail == head));
}

void Coada::Push(Nod &n)
{
	lista *aux = new lista(n);
	if(IsEmpty())
	{
		head = aux;
		tail = aux;
	}
	else
	{
		tail->leg = aux;
		tail = aux;
	}
}

Nod Coada::Pop()
{
	if(IsEmpty())
	{
		Nod n(-1);
		return n;
	}
	if(head == tail)
	{
		Nod n = head->ln;
		delete head;
		head = NULL;
		tail = NULL;
		return n;
	}
	else
	{
		Nod n = head->ln;
		lista *aux = head;
		head = head->leg;
		delete aux;
		return n;
	}
}

Nod Coada::Peek()
{
	if(IsEmpty())
	{
		Nod n(-1);
		return n;
	}
	return head->ln;
}

void Coada::Print()
{
	if(head == NULL)
	{
		std::cout << std::endl;
		return;
	}
	lista *aux = head;
	while(aux->leg != NULL)
	{
		std::cout << aux->ln.GetID() << ", "; 
		aux = aux->leg;
	}
	std::cout << aux->ln.GetID();
	std::cout << std::endl;
}