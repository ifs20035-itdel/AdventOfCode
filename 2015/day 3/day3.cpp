#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <set>

using namespace std;
using point = array<int,2>;

set<point> countHouses(string destination){
  point currentLocation= {0,0};
  set<point> visited_place;
  visited_place.insert(currentLocation);

  for(char dest : destination){
    switch (dest){
      case '^':
        currentLocation[1]+=1;
        break;
      case 'v':
        currentLocation[1]-=1;
        break;
      case '>':
        currentLocation[0]+=1;
        break;
      case '<':
        currentLocation[0]-=1;
        break;      
      default:
        cerr << "Error" << endl;
        break;
    }
    visited_place.insert(currentLocation);
  }
  // return visited_place.size();
  return visited_place;

}

int main(){
  ifstream file("input.txt");
  string route;
  file >> route;
  string santa_route="";
  string robo_santa_route="";

  for(int i=0;i<route.length();i++){
    if(i%2==0){
      santa_route += route[i];
    } else{
      robo_santa_route += route[i];
    }
  }

  set<point> santa_house = countHouses(santa_route);
  set<point> robo_santa_house = countHouses(robo_santa_route);

  santa_house.insert(robo_santa_house.begin(), robo_santa_house.end());

  cout << "Result : " << santa_house.size()<< endl;
  // return 0;
}
