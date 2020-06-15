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
el puntero solo apunta al siguiente. 
*/

struct Node{
	int dato;
	Node *siguiente;
};

void insertarLista(Node *&,int);

int main(){
	Node *lista=NULL;
	int dato;
	cout<<"Digite un numero";cin>>dato;
	insertarLista(lista,dato);
	return 0;
}

void insertarLista(Node *&lista,int n){
	Node *nuevo_Node=new Node();
	nuevo_Node->dato=n;

	Node *aux1=lista;
	Node *aux2;

	while((aux1 != NULL)&&(aux1->dato < n)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(lista==aux1){
		lista=nuevo_Node;
	}
	else{
		aux2->siguiente=nuevo_Node;
	}
	nuevo_Node->siguiente=aux1;
	cout<<"\tElement " <<n<<" Insertado"<<endl;
}


