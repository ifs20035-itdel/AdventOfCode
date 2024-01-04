#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <set>

using namespace std;
using point = array<int,2>;

int countHouses(string destination){
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
  return visited_place.size();
  //return visited_place;

}

int main(){
  ifstream file("input.txt");
  string route;
  file >> route;

  cout << "Result : " << countHouses(route) << endl;

  // 2nd part
  string santa = "";
  string robo_santa = "";
  for(int i = 0; i<route.length();i++){
    if(i%2==0){
      santa+=route[i];
    } else{
      robo_santa+=route[i];
    }
  }

  // cout << "Santa \n" << santa << "\n" << "Robo santa: \n" << robo_santa << endl;
  //cout << countHouses(santa);
  //cout << countHouses(robo_santa);
  // cout << "Result : " << final_house.size() << endl;

}
