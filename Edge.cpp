#include "Edge.hpp"

Edge::Edge(Edge &n)
{
	first = n.Get_first();
	second = n.Get_second();
	Cost = n.GetCost();
}
/*
Edge::~Edge()
{
	delete first, second;
}
*/