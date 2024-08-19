#include <iostream>
#include <stdlib.h>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;

//Clase de alarma 
class Alarm{
  public:
  //Establece la estructura de la alarma
    struct Node{ 
      int duration;   
      int day;
      int hour;
      Node(int dt, int d, int h):duration(dt), day(d), hour(h){}; //Constructor
    };
    void addAlarm(int quantity);//Agregar alarma 
    Node nextAlarm(); //Obtener la alarma mas proxima
  private:
    class Compare{ //Clase anidada para usarla a manera de comparador
    public:
      //implementacion de functor
      bool operator()(const Alarm::Node& a,const Alarm::Node& b ){
        //epoch actual en segundos
        auto tp = system_clock::now().time_since_epoch();
        auto dtNow = duration_cast<seconds>(tp).count(); 
        
        /*Utilizado para determinar cual de las alarmas esta 
          mas proxima con respecto al tiempo actual
        */

        // si a es mayor que el epoch actual (sg) y menor o igual que b 
        if(a.duration > dtNow && a.duration <= b.duration){
          return false; //tiene mayor prioridad 
         // si b es mayor que el epoch actual (sg) y menor o igual que a 
        }else if(b.duration > dtNow && b.duration <= a.duration){
          return true; //tiene mayor prioridad
        }
        //en caso de que sean alarmas atrasadas se verifican cual de dos ocurrio antes
        return a.duration > b.duration; 
      }
    }; 
    priority_queue<Node, vector<Node>, Compare> pq; //se establece la priority queue 
    int randomDuration(); // una funcion 
};


int Alarm::randomDuration()
{
  //consigue el epoch del tiempo actual
  auto tp = system_clock::now();
  auto dt = duration_cast<seconds>(tp.time_since_epoch()).count();
  int randNum = rand() % 2 + 1; //numero aleatorio para decidir
  int randomdt; //almacena el tiempo aleatorio de la nueva alarma

  /*Utilizado para generar de manera dinamica
  las alarmas proximas y pasadas apartir del tiempo actual
  */ 
  if(randNum == 2){ // si es 2
    randomdt = dt + rand()%259,200; //suma al epoch actual 
  }else{
    randomdt = dt - rand()%259,200; //resta al epoch actual 
  }
  return randomdt; 
}

void Alarm::addAlarm(int quantity)
{
  /*Utilizado para insertar un numero determinado de alarmas
    en el que se establecen los valores de la estructura que se
    indica en la clase.
  */
  for(int i =0; i<= quantity; i++){
    //Almacena el tiempo del epoch para extraer dia y hora
    time_t timeStmp= randomDuration();
    //Establece en la estructura para representar hora y fecha desglosada
    //Se realiza mediante un puntero para accesar a los atributos del dia y hora 
    tm* timeStr = localtime(&timeStmp);
    Node alarm(timeStmp, timeStr->tm_mday,  timeStr->tm_hour);
    pq.push(alarm); 
  }
}


Alarm::Node Alarm::nextAlarm(){

  /*
    Ya que solo regresa nodos, se coloca 
    un mensaje de error para que no caiga
    el programa
   */
  if(pq.empty())
  {
    //si esta vacia lanza un error
    throw runtime_error("pila vacia");
  
  }

  /*Se hace este proceso para 
  sacar la proxima alerta conforme las 
  iteraciones. 
  */
  
  Node topNode = pq.top(); // se almacena la alarma mas proxima 
    pq.pop(); //la elimina
    return topNode; //regresa la alarma 
}

int main()
{
  srand(static_cast<unsigned>(time(0)));
  Alarm a;
  a.addAlarm(10000);
  
  for(int i =0;  i < 10000; i++){
    auto alarma = a.nextAlarm();
    cout<<alarma.day<<" "<<alarma.hour<<endl; 
  }
  
}