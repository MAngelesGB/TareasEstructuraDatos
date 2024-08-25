#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<chrono>
#include<random>
using namespace std; 
using namespace chrono; 


class Alarm{
  public:
    struct Node{
      long duration;
      Node(long dt):duration(dt){};
    };
    void addAlarm(int quantity, long nowdt);
    vector<long> nextClosestAlarm(long value);
  private:
    class Compare{
      public:
        bool operator()(const Alarm::Node a, const Alarm::Node b){
          return a.duration < b.duration; 
        }
    };
    priority_queue<Alarm::Node, vector<Alarm::Node>, Compare> pq; 
    long randomDuration(long nowdt);
};

long Alarm:: randomDuration(long nowdt){
  random_device rd; 
  mt19937 gen(rd());
  uniform_int_distribution<> dist(-86400, 86400);
  long r = dist(gen);

  return nowdt + r;  
}

void Alarm::addAlarm(int quantity, long nowdt){ 
  srand(time(0)); 
  for(int i = 0; i < quantity; i++){
    long dt = randomDuration(nowdt); 
    Node alarm(dt); 
    pq.push(alarm);
  }
}

vector<long> Alarm::nextClosestAlarm(long nowdt){
  vector<long> closestAlarm;
  while(!pq.empty()){
    if(nowdt<pq.top().duration){
      closestAlarm.push_back(pq.top().duration);
    }
    pq.pop(); 
  }
  return closestAlarm; 
}

int main(){
  Alarm a;
  vector<long> nextAlarm; 

  auto tp = system_clock::now();
  auto dt = duration_cast<seconds>(tp.time_since_epoch()).count();
  
  a.addAlarm(10000,dt);
  nextAlarm = a.nextClosestAlarm(dt); 

  for(int i = 0; i < nextAlarm.size(); i++)
  {
    cout<<nextAlarm[i]<<endl; 
  }
}