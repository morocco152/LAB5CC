#include<iostream> 
using namespace std; 
/*
Concepto de Lista Enlazada :
****************************
Estructura de datos dinámica.
Lista con un numero de Nodes de dos campos, un enlace a al sigiente Node y un valor, que puede ser de cualquier tipo.

Listas simplemente enlazada:
****************************
Cada Node tiene solo un enlace al siguiente Node y es eficiente en recorridos directos. 
el puntero solo apunta al siguiente elemento */

class LinkedList{
private:
	class Nodo{
	public:
		int elem;
		Nodo *sigui;
		
		Nodo(){
			sigui = NULL;
		}
	};
	
	Nodo *cabeza;
	int size;

public:
	LinkedList();
	~LinkedList();
	void insert(int);
	void remove(int);
	void print();
};




LinkedList::LinkedList(){
	cabeza = NULL;
	size = 0;
}

LinkedList::~LinkedList(){
	Nodo *reco = cabeza;
	Nodo *eliminar;
	int cont = 0;
	
	while(cont != size){
		eliminar = reco;
		reco = reco->sigui;
		delete eliminar;
	  cont++;
	}
}

/* Insertar elemeto y ordenar */
void LinkedList::insert(int x){
	Nodo *nuevo = new Nodo();
	nuevo->elem = x;
	
	if(cabeza == NULL)
	{
		cabeza = nuevo;
	}
	else
	{
		if(x < cabeza->elem)
		{
			nuevo->sigui = cabeza;
			cabeza = nuevo;
		}
		else
		{
			Nodo *reco = cabeza;
			Nodo *atras = cabeza;
			int cont = 1;
			
			while(x >= reco->elem  &&  cont != size ){
				atras = reco;
				reco = reco->sigui;
				cont++;
			}
			
			if(x >= reco->elem)
			{
				reco->sigui = nuevo;
			}
			else
			{
				nuevo->sigui = reco;
				atras->sigui = nuevo;
			}
				
		}
		
	}
	
	size++;
	
}

/* Eliminar un elemento de acuedo a la posición 1,2,..n */
void LinkedList::remove(int pos){
	if(pos <= size)
	{
		Nodo *eliminar;
		
		if(pos == 1)
		{
			eliminar = cabeza;
			cabeza = cabeza->sigui;
		}
		else
		{
			Nodo *reco;
			reco = cabeza;
			
			for(int i=1; i<=pos-2; i++){
				reco = reco->sigui;
			}
			Nodo *prox = reco->sigui;
			reco->sigui= prox->sigui;
			eliminar = prox;
		}
		
		delete eliminar;
		
	}
	size--;
}

/*Imprime la lista*/
void LinkedList::print(){
	Nodo *reco = cabeza;
	int cont = 0;
	
	while(cont != size){
		cout << reco->elem << " ";
		reco = reco->sigui;
		++cont;
	}
	cout << "\n";
}


int main(){
	LinkedList eo;
	eo.insert(1);
	eo.insert(2);
	eo.insert(4);
	eo.print();
  eo.remove(3);
  eo.print();
  eo.insert(3);
  eo.print();
	return 0;
}



