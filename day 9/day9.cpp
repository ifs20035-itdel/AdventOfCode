#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    string line;
    int totalDifference = 0;

    while (getline(file, line)) {
        totalDifference += calculateDifference(line);
    }

    file.close();

    cout << "Total difference: " << totalDifference << endl;

    return 0;
}