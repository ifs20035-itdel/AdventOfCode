#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int calculateDifference(const string& line) {
    int codeLength = line.length();
    int memoryLength = 0;
    
    for (size_t i = 1; i < line.length() - 1; ++i) {
        if (line[i] == '\\' && i + 1 < line.length()) {
            if (line[i + 1] == '\\' || line[i + 1] == '"') {
                i++; // Skip next character
            } else if (line[i + 1] == 'x' && i + 3 < line.length()) {
                i += 3; // Skip 3 char for hexadec
            } 
        }
        memoryLength++;
    }

    return codeLength - memoryLength;
}

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