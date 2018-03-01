#include <iostream>

template <typename T>
class CoadaPrioritara
{
private:
	class lista
	{
	public:
		T ln;
		lista *leg;
	public:
		lista(T &n, lista *l = NULL)
		: ln(n), leg(l){}
	};
	lista *head, *tail;
	bool sem;
public:
	CoadaPrioritara(bool sem);
	~CoadaPrioritara();
	void Push(T);
	T Pop(T);
	int Compare(T, T, bool);
};

template <typename T>
CoadaPrioritara<T>::CoadaPrioritara(bool sem)
{
	head = NULL;
	tail = NULL;
	this->sem = sem;
}

template <typename T>
void CoadaPrioritara<T>::Push(T sth)
{
	lista *aux = new lista(sth);
	if(head == NULL)
	{
		aux->leg = NULL;
		head = aux;
		tail = aux;
	}
	else
	{
		if(Compare(Haux, sth, sem) != 1)
		{
			Haux->leg = head;
			head = Haux;
			return;
		}
		lista* Haux = head;
		while(Haux->leg != NULL)
		{
			if(Compare(Haux->leg->ln, sth, sem) != 1)
			{
				break;
			}
			Haux = Haux->leg;
		}
		aux->leg = Haux->leg;
		Haux->leg = aux;
		if(aux->leg == NULL)
		{
			tail = aux;
		}
	}
}

template <typename T>
int CoadaPrioritara<T>::Compare(T n, T n1, bool b)
{
	if(n == n1)
	{
		return 0;
	}
	if(n1 > n2)
	{
		if(b)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		if(b)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
}