#include <bits/stdc++.h> 
using namespace std;

template<typename T>

class LinkedList{ // se inicia la lista
private:
  class Nodo{
  public:
    int elem;
    Nodo<T> *sigui;
    
    Nodo(){
      sigui = NULL;
    }
  };
  
  Nodo<T> *cabeza;
  Nodo<T> *size;


public:
  LinkedList();
  ~LinkedList();
  void insert(int);
  void remove(int);
  void print();

  class iterator{
    friend class LinkedList;
    private:
      Node<T> *NodePtr;
      //Constructor private
      iterator(Node<T> *newPtr): NodePtr(newPtr){};
    public:
      iterator() : NodePtr(nullptr){};

      //sobrecarga <!=>
      bool operator!=(const iterator& itr) const{
        return NodePtr != itr.NodePtr;
      }
      //sobrecarga <*>
      T& operator*() const {
          return NodePtr->next->data;
        }
        //sobrecarga <++>
        iterator operator++(int) {
          iterator temp = *this;
          NodePtr = NodePtr->next;
          return temp;
        }
  };

};




LinkedList::LinkedList(){
  cabeza = NULL;
  size = 0;
}

LinkedList::~LinkedList(){
  Nodo<T> *reco = cabeza;
  Nodo<T> *eliminar;
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
  Nodo<T> *nuevo = new Nodo<T>();
  nuevo->elem = x;
  Nodo<T> *aux1 = cabeza;
  Nodo<T> *aux2;
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
      Nodo<T> *reco = cabeza;
      Nodo<T> *atras = cabeza;
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


/*Imprime la lista*/
void LinkedList::print(){
  Nodo<T> *reco = cabeza;
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
  eo.insert(3);
  eo.print();
  return 0;
}
