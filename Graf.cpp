#include <fstream>
#include "Graf.hpp"
#include "Coada.hpp"
#include "Stiva.hpp"
#include <chrono>
#include <random>
#include <limits>
#include <thread>

Graf::Graf(ListaEdge &toCopy)
{
	edges = toCopy;
}

Graf::Graf(ListaNod &toCopy)
{
	nods = toCopy;
}

Graf::Graf(ListaNod &toCopyNods, ListaEdge &toCopyEdge)
{
	edges = toCopyEdge;
	nods = toCopyNods;
}

void Graf::Add(Nod n)
{
	if(!Check(n.GetID()))
	{
		nods.AddNod(n);
	}
}

void Graf::Add(int ID1, int ID2)
{
	Nod *f = NULL, *s = NULL;
	int size = nods.Size();
	for(int i = 0; i < size; i++)
	{
		Nod *n = nods.Getn_nod(i);
		if((n->GetID() == ID1) 
			|| (n->GetID() == ID2))
		{
			if(f == NULL)
			{
				f = n;
			}
			else
			{
				s = n;
				Edge e(f, s);
				int seed = std::chrono::system_clock::now().time_since_epoch().count();
				std::mt19937 generator(seed);
				std::uniform_int_distribution<int> distribution(10,100);
				e.SetCost(distribution(generator));
				edges.AddEdge(e);
			}
		}
	}
}

Edge* Graf::GetEdge(int ID1, int ID2)
{
	if(!Check(ID1) || !Check(ID2))
	{
		return NULL;
	}
	if(ID1 == ID2)
	{
		return NULL;
	}
	int size = edges.Size();
	for(int i = 0; i < size; i++)
	{
		int F_ID = edges.Get_edge(i)->Get_first()->GetID();
		int S_ID = edges.Get_edge(i)->Get_second()->GetID();
		if(((F_ID == ID1) && (S_ID == ID2))
		 || ((F_ID == ID2) && (S_ID == ID1)))
		{
			return edges.Get_edge(i);
		}
	}
}

bool Graf::Check(int ID)
{
	int size = nods.Size();
	for(int i = 0; i < size; i++)
	{
		if(nods.Getn_nod(i)->GetID() == ID)
		{
			return true;
		}
	}
	return false;
}

bool Graf::Check(int ID1, int ID2)
{
	int size = edges.Size();
	for(int i = 0; i < size; i++)
	{
		int first = edges.Get_edge(i)->Get_first()->GetID();
		int second = edges.Get_edge(i)->Get_second()->GetID();
		if(((first == ID1) && (second == ID2)) 
			|| ((first == ID2) && (second == ID1)))
		{
			return true;
		}
	}
	return false;
}

ListaNod* Graf::GetNeighbours(int ID)
{
	ListaNod* res = new ListaNod;
	int size = edges.Size();
	for(int i = 0; i < size; i++)
	{
		if(edges.Get_edge(i)->Get_first()->GetID() == ID)
		{
			res->AddNod(*edges.Get_edge(i)->Get_second());
		}
		else if(edges.Get_edge(i)->Get_second()->GetID() == ID)
		{
			res->AddNod(*edges.Get_edge(i)->Get_first());
		}
	}
	return res;
}

void Graf::Print()
{
	int size = nods.Size();
	for(int i = 0; i < size; i++)
	{
		std::cout << nods.Getn_nod(i)->GetID() << " : ";
		ListaNod* Neighbours = GetNeighbours(nods.Getn_nod(i)->GetID());
		int size2 = Neighbours->Size();
		if(size2)
		{
			Neighbours->Print();
			std::cout << "( ";
			for(int j = 0; j < size2; j++)
			{
				Edge *e = GetEdge(nods.Getn_nod(i)->GetID(), Neighbours->Getn_nod(j)->GetID());
				std::cout << e->GetCost() << " ";
			}
			std::cout << ")";
		}
		std::cout << "\n";
		delete Neighbours;
	}
}

void Graf::Remove(int i)
{
	nods.Remove(i);
	for(int j = 0; j < edges.Size();)
	{
		int first = edges.Get_edge(j)->Get_first()->GetID();
		int second = edges.Get_edge(j)->Get_second()->GetID();
		if((first == i) || (second == i))
		{
			edges.Remove(first, second);
		}
		else
		{
			j++;
		}
	}
}

int Graf::Get_color(int ID)
{
	Nod *n = nods.Get_nod(ID);
	return n->GetColor();
}

bool Graf::Set_color(int ID, int color)
{
	Nod *n = nods.Get_nod(ID);
	if(n == NULL)
	{
		return false;
	}
	n->SetColor(color);
	return true;
}

void Graf::Clear_color()
{
	int size = nods.Size();
	for(int i = 0; i < size; i++)
	{
		nods.Getn_nod(i)->SetColor(0);
	}
}

bool Graf::IsConnected_BFS(int ID1, int ID2)
{
	if(!Check(ID1) || !Check(ID2))
	{
		return false;
	}
	if(ID1 == ID2)
	{
		return true;
	}
	Coada tail;
	ListaNod *n = GetNeighbours(ID1);
	int size = n->Size();
	Set_color(ID1, 1);
	for(int i = 0; i < size; i++)
	{
		tail.Push(*n->Getn_nod(i));
	}
	while(!tail.IsEmpty())
	{
		int ID_aux = tail.Pop().GetID();
		if(ID_aux == ID2)
		{
			Clear_color();
			delete n;
			return true;
		}
		Set_color(ID_aux, 1);
		delete n;
		n = GetNeighbours(ID_aux);
		int size = n->Size();
		for(int i = 0; i < size; i++)
		{
			if(n->Getn_nod(i)->GetColor() == 0)
			{
				tail.Push(*n->Getn_nod(i));
			}
		}
	}
	Clear_color();
	delete n;
	return false;
}

bool Graf::IsConnected_DFS(int ID1, int ID2)
{
	if(!Check(ID1) || !Check(ID2))
	{
		return false;
	}
	if(ID1 == ID2)
	{
		return true;
	}
	Stiva stack;
	ListaNod *n = GetNeighbours(ID1);
	int size = n->Size();
	Set_color(ID1, 1);
	for(int i = 0; i < size; i++)
	{
		Set_color(n->Getn_nod(i)->GetID(), 1);
		stack.Push(*n->Getn_nod(i));
	}
	while(!stack.IsEmpty())
	{
		Nod n1 = stack.Pop();
		std::cout << n1.GetID() << " ";
		if(n1.GetID() == ID2)
		{
			std::cout << std::endl;
			Clear_color();
			delete n;
			return true;
		}
		int aux = n1.GetID();
		delete n;
		n = GetNeighbours(aux);
		int size = n->Size();
		for(int i = 0; i < size; i++)
		{
			if(Get_color(n->Getn_nod(i)->GetID()) == 0)
			{
				stack.Push(*n->Getn_nod(i));
				Set_color(n->Getn_nod(i)->GetID(), 1);
			}
		}
	}
	std::cout << std::endl;
	Clear_color();
	delete n;
	return false;
}

int* Graf::Short_dist(int ID)
{
	
}

Graf* Graf::ReadFromFile(char *s)
{
	std::ifstream f(s);
	if(!f.is_open())
	{
		return NULL;
	}
	int NodSize;
	f >> NodSize;
	Graf *g = new Graf;
	for(int i = 0; i < NodSize; i++)
	{
		int aux1, v;
		f >> aux1;
		Nod n(aux1);
		g->Add(n);
		f >> v;
		for(int j = 0; j < v; j++)
		{
			int aux2;
			f >> aux2;
			if(aux2 < aux1)
			{
				g->Add(aux2, aux1);
			}
		}
	}
	return g;
}