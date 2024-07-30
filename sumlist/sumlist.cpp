#include<iostream>
#include<stdlib.h>

using namespace std; 

struct Node{
  int num;
  Node *next; 
}; 

Node* linkedList1();
Node* linkedList2();
Node* result(Node *list, int num); 

Node* linkedList1(){
  Node *head = new Node{1, nullptr};
  head->next = new Node{2, nullptr};
  head->next->next = new Node{7, nullptr};
  return head; 
}

Node* linkedList2(){
  Node *head = new Node{9, nullptr};
  head->next = new Node{8, nullptr}; 
  return head; 
}

Node* result(Node *list, int num){
  Node *newNode = new Node{num, nullptr}; 

  if(list == nullptr){
    list = newNode;
  }else{
    while(list->next != nullptr){
      list = list ->next;
    }
    list->next = newNode; 
  }
}

int main(){
  Node *list = nullptr; 
  Node *list1 = linkedList1(); 
  Node *list2 = linkedList2(); 
  bool flag = false;

  while(flag != true){
    
  }
  return 0; 
}