#include <iostream>
#include <fstream>
#include "Graf.hpp"

int main()
{
	Graf *g = new Graf;
	std::ifstream f("in1.txt");
	int NodSize;
	f >> NodSize;
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
	g->Print();
	delete g; 
	return 0;
}
