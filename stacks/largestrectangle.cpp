#include<iostream>
#include<stdlib.h>
#include<stack>
#include<algorithm> //usar la funcion max
#include<vector>
using namespace std;

int largestRectangle(vector<int>h){ 
  int maxArea = 0;
  int arrSize = h.size();
  stack<int> index; 

  for(int i = 0; i < arrSize; i++ ){ //Recorre el array hasta que termine
  /* continua si esta vacio el stack, Y si el alto actual es menor 
  que el alto en la posicion almacenada */
    while(!index.empty() && h[i] < h[index.top()]){ 
      int height = h[index.top()]; //almacena la altura segun el indice de la pila
      index.pop();//retira el top

      //si esta vacia la pila, regresa el indice actual
      //de lo contrario resta el indice actual, con el indice de la pila, - 1;
      int width = index.empty() ? i : i - index.top() - 1;

      /*devuelve el valor mas alto entre el valor actual de maxArea
      y el area del siguiente rectangulo*/
      maxArea = max({maxArea, height*width});
    }
    index.push(i); //inserta el indice del array a la pila; 
  }

  while(!index.empty()){ //Continua hasta que la pila este vacia
    int height = h[index.top()]; //Obtiene el alto segun el indice almacenado en la pila
    index.pop();//retira el top de la pila 

    //si esta vacia la pila, regresa la longitud del vector
    /*de lo contrario, resta la longitud del vector,
     con el indice top almacenado en el stack, - 1 */
    int width = index.empty()?arrSize: arrSize - index.top() - 1;

    /*determina el numero mayor entre, el valor actual de maxArea y
    del area del siguiente rectangulo*/
    maxArea = max({maxArea, height*width});
  }

  //retorna el valor maximo; 
  return maxArea; 
}

int main(){
  vector<int> arr = {2,1,5,6,2,3}; 
  
  int max = largestRectangle(arr);

  cout<<max; 

}
