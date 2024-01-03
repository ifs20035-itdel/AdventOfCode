#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>

using namespace std;
using xy = array<int, 2>;
xy point = {0,0}; 
vector<xy> global_map = {{0,0}};

void countHouses(char arrow){
  if(arrow == '^'){
    point[1]+=1;
  } else if (arrow == 'v'){
    point[1]-=1;
  } else if (arrow == '<'){
    point[0]-=1;
  } else if (arrow == '>'){
    point[0]+=1;
  } else {
    cerr << "Error" << endl;
  }

  for(int i =0;i<global_map.size();i++){
    if(global_map[i] != point){
      global_map.push_back(point);
    }
  }
}

int main(){
  ifstream file("input.txt");
  string puzzle;
  file >> puzzle;

  for(int i=0;i<puzzle.length();i++){
    countHouses(puzzle[i]);
  }
  cout << "House : " << global_map.size() << endl;
}
