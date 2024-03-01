#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream file("input.txt");
    if(!file){
        cerr << "Unable to open file" << endl;
        return 1;
    }
    
    string line;

    while (getlien(file, line)) {
        return 0;
    }
    file.close();
    
    cout << "result: " << endl;

    return 0;
}
