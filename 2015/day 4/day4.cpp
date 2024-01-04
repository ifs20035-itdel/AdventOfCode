#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <openssl/evp.h>
#include <cstdio>
#include <ostream>

using namespace std;

string md5(const string& content) {
  EVP_MD_CTX*   context = EVP_MD_CTX_new();
  const EVP_MD* md = EVP_md5();
  unsigned char md_value[EVP_MAX_MD_SIZE];
  unsigned int  md_len;
  string        output;

  EVP_DigestInit_ex2(context, md, NULL);
  EVP_DigestUpdate(context, content.c_str(), content.length());
  EVP_DigestFinal_ex(context, md_value, &md_len);
  EVP_MD_CTX_free(context);

  output.resize(md_len * 2);
  for (unsigned int i = 0 ; i < md_len ; ++i)
    std::sprintf(&output[i * 2], "%02x", md_value[i]);
  return output;
}

string calculate (string base){
  int number = 0;
  string input_str = base + to_string(number);
  string hexa_hash= "";
  while(hexa_hash.substr(0,6) != "000000" ){
    input_str = base + to_string(number);
    hexa_hash = md5(input_str);
    number = number + 1; 
    cout << "Try " << number << " >> " << hexa_hash << endl;
  }
  return input_str; 
}

int main (int argc, char *argv[]) {
  ifstream file("input.txt");
  string problem;
  file >> problem;

  // NEED MD5 hash library -> libssl openssl. Maybe next time
  cout << "Result: " << calculate(problem) << endl;

  return 0;
}
