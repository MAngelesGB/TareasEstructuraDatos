#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class LinkedList{
  private:
    struct Node{
      int id;
      int age; 
      int weight; 
      string name; 
      Node *next; 
    }; 
    Node *head;
  public: 
    LinkedList():head(nullptr){} //Lista de inicializacion de miembros
    ~LinkedList(); //Destructor 

    void insert(int id, int age, int weigth, string name);
    void insertFirst (int id , int age, int weigth, string name); 
    Node* search(int id);
    bool deleteNode(int id);
    bool deleteFirstNode(); 
}; 

LinkedList::~LinkedList(){ //Destructor, libera memoria al final
  Node *current = head; 
  Node *nextNode = nullptr; 
  while(current != nullptr){
    nextNode = current->next; 
    delete current;
    current = nextNode; 
  }
}

//insert first Node
void LinkedList:: insertFirst(int id, int age, int weigth, string name){
  Node *newNode = new Node{id, age, weigth, name, nullptr}; //Ingresar datos a la estructura

  if(head == nullptr){
    head = newNode; 
  }
  else{
    newNode ->next = head; 
    head = newNode; 
  }
}

//Insert Node
void LinkedList:: insert(int id, int age, int weigth, string name){
  Node *newNode = new Node{id, age, weigth, name, nullptr}; //Ingresar datos a la estructura

  if(head == nullptr){
    head = newNode;
  }else{
    Node *aux = head;

    while(aux->next != nullptr){
      aux = aux->next;  
    }

    aux->next = newNode; 
  }
}

//Search node
LinkedList:: Node* LinkedList:: search(int id){
  if(head == nullptr){
    return nullptr; 
  }else{
    Node *aux = head; 
    while(aux != nullptr){
      if(aux->id == id){
        cout<<aux->name; 
        return aux;
      }
      aux = aux->next; 
    }
    return nullptr;
  }
}

//Delete first node
bool LinkedList:: deleteFirstNode(){
  if (head  == nullptr){
    return false;
  }else{
    Node *temp = head; 
    head = head->next; 
    delete temp; 
    return true; 
  }
}   

//Delete node
bool LinkedList:: deleteNode (int id){
  if(head == nullptr){
    return false; 
  }else{
    Node *aux = head;
    Node *temp = nullptr; 
    while(aux->next != nullptr){
      if(aux->next->id == id){
        temp = aux->next; 
        aux->next = aux->next->next; 
        delete temp; 
        return true; 
      }
      aux = aux->next; 
    }
    return false; 
  }
}

/*int main(){
  LinkedList list;


  list.insert(1, 18, 60, "Humano1"); 
  list.insert(2, 18, 60, "Humano2"); 
  list.insert(3, 18, 60, "Humano3"); 
  list.search(1); 
  list.search(3); 
  list.deleteNode(2); 
  list.deleteFirstNode(); 
  
}*/
