#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    ifstream file("input.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            //lights_house(line);
        }
        file.close();
    } else {
        cout << "Unable to open file";
        return 1;
    }

    cout << "Result : " << endl;
    return 0;
}
