#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

int extra_paper(int num1, int num2, int num3){
    if(num1==num2 && num1==num3){
        return num1*num2;
    }
    int maxNum = max({num1, num2, num3});

    if (maxNum == num1){
        return num2*num3;
    } else if (maxNum == num2){
        return num1*num3;
    } else {
        return num1*num2;
    }
}

int wrapped(int num1, int num2, int num3){
    return (2*num1*num2 + 2*num2*num3 + 2*num1*num3) + extra_paper(num1, num2, num3);
}

int main(){
    int result = 0;
    string filename = "input.txt";

    ifstream file(filename);
    string line;
    int a,b,c;
    char x;

    while(getline(file, line)){
        stringstream ss(line);
        if (ss>> a >> x >> b >> x >> c){
            result = result + wrapped(a,b,c);
        } else {
            cerr << "Error parsing line: " << line << endl;
        }
    }

    cout << "Result: " << result << endl;
}