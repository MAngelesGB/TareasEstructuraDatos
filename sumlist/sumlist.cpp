#include<iostream>
#include<stdlib.h>

using namespace std; 

struct Node{
  Node *before; 
  int num;
  Node *next; 
}; 

Node* linkedList1();
Node* linkedList2();
Node* createList(Node *&list, int num); 
Node* reverseList(Node *); 
void print(Node *); 

Node* linkedList1(){
  Node *head = new Node{nullptr, 1, nullptr};

  head->next = new Node{nullptr, 1, nullptr}; 
  head->next->before = head;

  head->next->next = new Node{nullptr, 1, nullptr};
  head->next->next->before = head->next; 

  return reverseList(head); 
}

Node* linkedList2(){
  Node *head = new Node{nullptr, 8, nullptr};

  head->next = new Node{nullptr, 5, nullptr}; 
  head->next->before = head;
  
  return reverseList(head); 
}

Node* reverseList(Node *head){
  Node *temp = head; 
  while(temp->next != nullptr){
    temp = temp->next;
  }
  return temp; 
}

Node* createList(Node *&list, int num){
  Node *newNode = new Node{nullptr, num, nullptr};
  
  if(list == nullptr){
    list = newNode;
  }else{
    Node *temp = list;
    while(temp->next != nullptr){
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->before = temp;
  }
  return list; 
}

void print(Node *list){
  while(list != nullptr){
    cout<< list->num << " "; 
    list = list->before; 
  }
}

void sumList(int sum, Node *aux, Node *&head){
  if(sum > 9){
    if(aux->before != nullptr){
      int first = sum / 10;
      int second = sum % 10;  
      aux->before->num += first;
      createList(head, second); 
    }else{
      createList(head, sum); 
    }
  }else{
    createList(head, sum); 
  }
}

int main(){
  int sum; 
  Node *head = nullptr;
  Node *aux1 = linkedList1(); 
  Node *aux2 = linkedList2(); 
  bool flag = false;


  while(flag != true){
    if(aux1 != nullptr && aux2 != nullptr){
      sum = aux1->num + aux2->num; 
      sumList(sum, aux1, head); 
    }else if(aux1 != nullptr && aux2 == nullptr){
      createList(head, aux1->num); 
    }else{
      flag = true; 
    }

    if(aux1 != nullptr){
      aux1 = aux1->before; 
    }
    if(aux2 != nullptr){
      aux2 = aux2->before;
    }
  }

  print(reverseList(head)); 
}