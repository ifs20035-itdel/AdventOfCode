#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <ostream>
#include <string>

using namespace std;

bool containsAny(const std::string& str, const std::vector<std::string>& substrings) {
    for (const auto& substring : substrings) {
        if (str.find(substring) != std::string::npos) {
            return true;
        }
    }
    return false;
}

int niceString(const vector<string> &nice){
  const string vowel = "aiueo";
  vector<string> forbid_substr = {"ab", "cd", "pq", "xy"};
  int nice_string = 0;
  
  for (const auto& prob : nice){
    bool vowel_check = false;
    bool double_char = false;

    // check forbidden string
    bool forbid = containsAny(prob, forbid_substr);
    if(forbid){
      continue;
    }

    int count_vowel = 0;
    char prev = '\0';
    
    for (char ch : prob){
      
      // check vowel
      if (vowel.find(ch) != string::npos) {
        count_vowel++;
        if(count_vowel >=3){
          vowel_check = true;
        }
      }

      // check double char
      if(ch == prev){
        double_char = true;
      } else {
        prev = ch; 
      }
    }
    if(vowel_check && double_char){
      cout << "Nice string >> " << prob << endl;
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
