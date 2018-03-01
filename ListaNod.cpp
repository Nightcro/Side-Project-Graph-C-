#include "ListaNod.hpp"
#include <iostream>

ListaNod::~ListaNod()
{
	while(root != NULL)
	{
		lista *aux = root;
		root = root->leg;
		delete aux;
	}
}

void ListaNod::AddNod(Nod &ln)
{
	lista *aux = new lista(ln);
	aux->leg = root;
	root = aux;
}

void ListaNod::Remove(int i)
{
	lista *aux1 = root, *aux2 = root;
	while(aux2->ln.GetID() != i)
	{
		aux1 = aux2;
		aux2 = aux2->leg;
		if(aux2 == NULL)
		{
			return;
		}
	}
	aux1->leg = aux2->leg;
	delete aux2;
}

void ListaNod::Print()
{
	if(root == NULL)
	{
		std::cout << std::endl;
		return;
	}
	lista *aux = root;
	while(aux->leg != NULL)
	{
		std::cout << aux->ln.GetID() << ", "; 
		aux = aux->leg;
	}
	std::cout << aux->ln.GetID();
}

int ListaNod::Size()
{
	if(root == NULL)
	{
		return 0;
	}
	int counter = 0;
	lista *aux = root;
	while(aux != NULL)
	{
		counter++;
		aux = aux->leg;
	}
	return counter;
}

Nod* ListaNod::Getn_nod(int i)
{
	lista *aux = root;
	while(i)
	{
		i--;
		aux = aux->leg;
	}
	return &aux->ln;
}

Nod* ListaNod::Get_nod(int ID)
{
	lista *aux = root;
	while(aux != NULL)
	{
		if(aux->ln.GetID() == ID)
		{
			return &aux->ln;
		}
		aux = aux->leg;
	}
	return NULL;
}

void ListaNod::operator=(ListaNod &toCopy)
{
	while(root != NULL)
	{
		lista *aux = root;
		root = root->leg;
		delete aux;
	}
	int size = toCopy.Size();
	root = new lista(*toCopy.Get_nod(0));
	lista *p = root;
	for(int i = 1; i < size; i++)
	{
		lista *aux = new lista(*toCopy.Get_nod(i));
		p->leg = aux;
		p = aux;
	}
}