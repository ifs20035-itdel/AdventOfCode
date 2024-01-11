#include <iostream>
#include <fstream>
#include <string>

int calculateDifference(const std::string& line) {
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
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    std::string line;
    int totalDifference = 0;

    while (std::getline(file, line)) {
        totalDifference += calculateDifference(line);
    }

    file.close();

    std::cout << "Total difference: " << totalDifference << std::endl;

    return 0;
}
