#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
​
class Car{
  public:
  int speed,price;
  string color;
​
  //constructor
  Car(int s, int p, string c){
    speed = s;
    price = p;
    color = c;
  }
​
};
​
//Custom comparator for Car class
bool compareCars(const Car& c1, const Car& c2){
  //sort by speed
  //return c1.speed <= c2.speed;
​
  //sort by price
  //return c1.price <= c2.price;
​
  //sort by color (lexicographic comparison)
  return c1.color <= c2.color;
}
​
int main(){
  Car cars[5] = {
    {500,100000,"Black"},
    {100,3000,"Red"},
    {400,9000,"Grey"},
    {200,1000,"Blue"},
    {300,27000,"Green"},
  };
​
  sort(cars,cars+5,compareCars);
​
  for(int i=0; i<5; ++i){
    cout<<cars[i].speed<<' '<<cars[i].price<<' '<<cars[i].color<<endl;;
  }
}
​