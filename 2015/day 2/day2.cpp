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

int tie_bow(int num1, int num2, int num3){
    if(num1==num2 && num1==num3){
        return 2*(num1+num2);
    }
    int maxNum = max({num1, num2, num3});

    if (maxNum == num1){
        return 2*(num2+num3);
    } else if (maxNum == num2){
        return 2*(num1+num3);
    } else {
        return 2*(num1+num2);
    }
}

int wrapped(int num1, int num2, int num3){
    // Return the surface area + extra_paper
    return (2*num1*num2 + 2*num2*num3 + 2*num1*num3) + extra_paper(num1, num2, num3);
}

int ribbon_bow(int a, int b, int c){
    // Return the volume + extra to tie the bow
    return (a*b*c) + tie_bow(a,b,c);
}

int main(){
    int paper = 0;
    int ribbon = 0;
    string filename = "input.txt";

    ifstream file(filename);
    string line;
    int a,b,c;
    char x;

    while(getline(file, line)){
        stringstream ss(line);
        if (ss>> a >> x >> b >> x >> c){
            paper = paper + wrapped(a,b,c);
            ribbon = ribbon + ribbon_bow(a,b,c);
        } else {
            cerr << "Error parsing line: " << line << endl;
        }
    }

    cout << "Paper: " << paper << "\nRibbon: " << ribbon << endl;
}