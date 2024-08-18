#include <iostream>
#include <stdlib.h>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;

class Alarm{
  public:
    struct Node{ 
      int duration;   
      int day;
      int hour;
      Node(int dt, int d, int h):duration(dt), day(d), hour(h){}; 
    };
    void addAlarm(int quantity);
    Node nextAlarm();
  private:
    class Compare{
    public:
      bool operator()(const Alarm::Node& a, const Alarm::Node& b){
        return a.duration > b.duration;
      }
    }; 
    priority_queue<Node, vector<Node>, Compare> pq;
    int randomDuration();
};


int Alarm::randomDuration()
{
  auto tp = system_clock::now();
  auto dt = duration_cast<seconds>(tp.time_since_epoch());

  int randomdt = dt.count()+ rand()%86400; 
  return randomdt;
}

void Alarm::addAlarm(int quantity)
{
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
  if(pq.empty())
  {
    throw runtime_error("pila vacia");
  
  }
  Node topNode = pq.top();
    pq.pop();
    return topNode; 
}

int main()
{
  srand(static_cast<unsigned>(time(0)));
  Alarm a;
  a.addAlarm(10);
}