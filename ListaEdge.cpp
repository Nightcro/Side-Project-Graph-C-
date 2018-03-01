#include "ListaEdge.hpp"

ListaEdge::~ListaEdge()
{
	while(root != NULL)
	{
		lista *aux = root;
		root = root->leg;
		delete aux;
	}
}

void ListaEdge::AddEdge(Edge edg)
{
	lista *aux = new lista(edg);
	aux->leg = root;
	root = aux;
}

void ListaEdge::Remove(int st, int nd)
{
	lista *aux1 = root, *aux2 = root;
	while(((aux2->edg.Get_first()->GetID() != st) 
		|| (aux2->edg.Get_second()->GetID() != nd))
		&& ((aux2->edg.Get_first()->GetID() != nd) 
		|| (aux2->edg.Get_second()->GetID() != st)))
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

void ListaEdge::Print()
{
	lista *aux = root;
	while(aux != NULL)
	{
		std::cout << "(" << aux->edg.Get_first()->GetID()
			<< "," << aux->edg.Get_second()->GetID() << ") ";
		aux = aux->leg;
	}
	std::cout << std::endl;
}

int ListaEdge::Size()
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

Edge* ListaEdge::Get_edge(int i)
{
	lista *aux = root;
	while(i)
	{
		i--;
		aux = aux->leg;
	}
	return &aux->edg;
}

void ListaEdge::operator=(ListaEdge &toCopy)
{
	while(root != NULL)
	{
		lista *aux = root;
		root = root->leg;
		delete aux;
	}
	int size = toCopy.Size();
	root = new lista(*(toCopy.Get_edge(0)));
	lista *p = root;
	for(int i = 1; i < size; i++)
	{
		lista *aux = new lista(*(toCopy.Get_edge(i)));
		p->leg = aux;
		p = aux;
	}
}
