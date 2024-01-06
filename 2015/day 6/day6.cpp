#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int lightHouse(const vector<string> &light){
  
  return 0;
}

int main (int argc, char *argv[]) {
  ifstream file("input.txt");
  vector<string> input;
  string line;

  if(file.is_open()){
    while(getline(file, line)){
      input.push_back(line);
    }
    file.close();
  } else {
    cerr << "Unable to open file" << endl;
    return 1;
  }
  
  lightHouse(input);

  return 0;
}
