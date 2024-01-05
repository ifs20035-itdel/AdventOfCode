#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <ostream>
#include <string>

using namespace std;

bool checkPair(string prob){
  if(prob.length()<4){
    return false;
  }

  for(int i=0;i<prob.length()-3;i++){
    for(int j=i+2;j<prob.length()-1;j++){
      if(prob[i]==prob[j] && prob[i+1]==prob[j+1]){
        return true;
      }
    }
  }
  return false;
}

int niceString(const vector<string> &nice){ 
  int nice_string = 0;

  for(const auto& prob : nice) {
    bool repeat_letter = false;
    bool pair_letter = checkPair(prob);
    for(int i=0;i<(prob.length()-2);i++){
      if(prob[i] == prob[i+2]){
        repeat_letter = true;
      }
    }

    if(repeat_letter && pair_letter){
      nice_string++;
    }
  }
  cout << "Result : " << nice_string << endl;
  return 0;
}

int main (int argc, char *argv[]) {
  ifstream file("input.txt");
  vector<string> input;
  string line;

  if(file.is_open()){
    while(getline(file, line)) {
      input.push_back(line);
    }
    file.close();
  } else{
    cerr << "Unable to open file" << endl;
    return 1;
  }
  niceString(input);
  return 0;
}
