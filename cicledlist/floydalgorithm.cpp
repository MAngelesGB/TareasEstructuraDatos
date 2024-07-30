#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
  int num;
  Node*next;
}; 

Node* cycledList(Node* head);
Node* linkedList(); 
void printList(Node* head);
void cleanMemory(Node* head);

Node* linkedList(){
  Node* head = new Node{1, nullptr}; 
  Node* temp;;
  head->next = new Node{2, nullptr}; 
  head->next->next = new Node{3, nullptr};
  head->next->next->next = new Node{4, nullptr}; 
  temp = head->next->next;
  head->next->next->next->next = new Node{5, nullptr}; 
  head->next->next->next->next->next = temp;
  return head; 
}

Node* cycledList(Node* head){
  Node *turtle = head;
  Node *hare = head;

  //First part of algorithm
  while(hare != nullptr && hare->next != nullptr ){
    hare = hare->next->next;
    turtle = turtle->next; 
    if(hare == turtle){
      break; 
    }
  }

  if(turtle != hare){
    return head;
  }else{
      //second part of algorithm
    turtle = head;
    while(turtle != hare){
      turtle = turtle->next; 
      hare = hare->next;
    }
    //destruct cycle
    while(hare->next != turtle){
      hare = hare ->next; 
    }
    hare->next = nullptr; 
    return head; 
  }
}

void printList(Node *head){
  while(head->next != nullptr){
    cout<<head->num<<" ";
    head = head->next;  
  }
}

void cleanMemory(Node *head){
  Node *temp = head; 
  while(head != nullptr){
    temp = head;
    head = head->next;
    delete temp;  
  }
}

int main(){
  Node *head = linkedList(); 
  Node *head2; 
  //printList(head); 
  head2=cycledList(head);
  printList(head2); 
  cleanMemory(head2); 
}