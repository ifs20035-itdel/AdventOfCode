#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int encodeChar(const string& line) {
    int codeLength = line.length();
    int extendedLength = codeLength + 4;
    for (size_t i = 1; i < line.length() - 1; ++i) {
        if (line[i] == '\\' && i + 1 < line.length()) {
            if (line[i + 1] == '\\' || line[i + 1] == '"') {
                extendedLength += 2;
                i++; // Skip next character
            } else if (line[i + 1] == 'x' && i + 3 < line.length()) {
                extendedLength += 1;
                i += 3; // Skip 3 char for hexadec
            } 
        }
    }
    return extendedLength - codeLength;
}

int main(int argc, char const *argv[])
{
    ifstream file("input.txt");
    if(!file){
        cerr << "Unable to open file" << endl;
        return 1;
    }
    
    string line;
    int totalDifference = 0;

    while (getline(file, line)) {
        totalDifference += encodeChar(line);
    }
    file.close();
    
    cout << "result: " << totalDifference << endl;

    return 0;
}
