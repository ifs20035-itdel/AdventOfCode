#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream file("input.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            string x = quoted(line);
            cout << x.length() << " : " << endl;
            for(char c : x){
                cout << x << endl;
            }
            break;
        }
        file.close();
    } else {
        cout << "Unable to open file";
        return 1;
    }
    return 0;
}
