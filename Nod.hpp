#ifndef NOD_H
#define NOD_H

class Nod
{
private:
	int ID;
	int color;
public:
	Nod(int i): ID(i), color(0){}
	//Nod(Nod &ln);
	int GetID(){return ID;}
	int GetColor(){ return color; }
	void SetColor(int c){ color = c; }
	void SetID(int i){ ID = i; }
	bool operator==(Nod &n){return this->ID == n.GetID();}
	bool operator!=(Nod &n){return !(*this == n); }
	void operator=(Nod &n);
	void operator=(Nod n);
};

#endif