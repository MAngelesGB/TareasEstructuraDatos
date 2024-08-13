#include<iostream>
#include<stdlib.h>
#include<stack>
#include<vector>
#include<algorithm> //usar la funcion max 
using namespace std;

//Funcion para la suma de elementos de un stack
int sumStack(stack<int> s){
  int sum = 0;
  //Lo recorre hasta que el stack este vacio 
  while(!s.empty()){
    sum += s.top(); //realiza la suma de los valores en el top
    s.pop(); // retirar el elemento en el top
  } 
  return sum; //retorna la suma de los elementos
}

/*Ingresa una serie de elementos dinamicamente, 
pd: colocar el tipo de dato y luego el operador de referencia*/

void fillStack(vector<int>arr, stack<int> &s){
  for(int i = arr.size()-1; i >= 0; i--){
    s.push(arr[i]);
  }
}

int equalStacks(stack<int> h1, stack<int> h2, stack<int> h3){
  //Obtiene la suma de todos los stacks
  int sum1 = sumStack(h1);
  int sum2 = sumStack(h2);
  int sum3 = sumStack(h3);

  //Mientras las sumas sean distintas
  while(sum1 != sum2 || sum2 != sum3){
    int m = max({sum1, sum2, sum3}); //se obtiene la suma mas grande 

    //si alguno de las sumas coincide con el numero mayor
    if(sum1 == m){
      sum1 -= h1.top(); //resta el top a la suma
      h1.pop(); //retira el top
    }else if(sum2 == m){
      sum2 -= h2.top();
      h2.pop();
    }else if(sum3 == m){
      sum3 -= h3.top();
      h3.pop();
    }
  }
  return sum1; //retorna el alto
}

int main(){
  //Definicion de stack y elementos
  stack<int> h1, h2, h3;
  vector<int> arr1 = {3,2,1,1,1};
  vector<int> arr2 = {4,3,2};
  vector<int> arr3 = {1,1,4,1};

  //llenado de elementos
  fillStack(arr1, h1);
  fillStack(arr2, h2);
  fillStack(arr3, h3); 

  //Encuentra el alto entre los tres cilindros y lo imprime
  int height = equalStacks(h1,h2,h3);
  cout<<height;

}
