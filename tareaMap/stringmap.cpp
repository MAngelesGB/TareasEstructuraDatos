#include<iostream>
#include<stdlib.h>
#include <cstring> 
#include<vector>
#include<map>
#include<cctype>
#include<string>
using namespace std; 



int main(){
  /* 
    Definicion de alias de mapas y pares de insersion 
   */
  typedef map<string,vector<int>> mp; 
  typedef pair<string,vector<int>> prstr;

  mp mpstr; 
  /* Vector de conteo de repeticion de elementos 
    y posicion de elementos
  */
  vector<int> v = {1};
  /* 
    Contador de los elementos encontrados
   */
  map<string,vector<int>>::iterator i; 
  /*Acumulador de la posicion de los elementos*/
  int j = 1; 

  char str[]= "El sol brilla en el cielo, el sol da luz y calor, mientras las personas disfrutan del día. La gente va al parque, al parque donde el sol brilla más fuerte, y las familias pasan tiempo juntas. Los niños juegan en el parque, los niños ríen y corren, y el parque se llena de alegría. Las flores del parque también parecen más vivas, las flores se abren bajo el sol brillante. Al atardecer, el sol se oculta lentamente, y el parque se transforma en un lugar tranquilo.";

  //convertir el str en minusculas para evitar la diferenciacion por case sensitive
  for(char &x:str){
    x  = (char) tolower(x); 
  }

  /* Puntero para almacenar el string*/
  char *rest = str; 

  /* Puntero para almacenar el valor */
  char *token; 
  
  //Puntero para los delimitadores de los elementos
  const char *delimiters = " ,.";


  while((token = strtok_r(rest,delimiters,&rest)) ){
    i = mpstr.find(token);

    if(i!=mpstr.end()){ 
      i->second[0]++; //Conteo de la repeticion de elementos
      i->second.push_back(j); // Agrega la(s) posicion(es) del elemento
    }else{
      mpstr.insert(prstr(token,v));
      mpstr.find(token)->second.push_back(j);
    }

    j++;
  }

  for(i = mpstr.begin(); i != mpstr.end(); i++){
    j = 1; 
    cout<<i->first<<" | "<< i->second[0]<<" | ";
    while(j < i->second.size()){
      cout<<i->second[j]<<" ";
      j++;
    }
    cout<<endl; 
  }
}