#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <functional>
#include <string>
#include <vector>

using namespace std;

unsigned short calculate_wire(const string& wire, 
                              unordered_map<string, function<unsigned short()>>& circuit, 
                              unordered_map<string, unsigned short>& cache) {
    if (isdigit(wire[0])) {
        return static_cast<unsigned short>(stoi(wire));
    }

    if (cache.find(wire) == cache.end()) {
        cache[wire] = circuit[wire]();
    }

    return cache[wire];
}

int main() {
    unordered_map<string, function<unsigned short()>> circuit;
    unordered_map<string, unsigned short> cache;

    ifstream file("input.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};

            if (tokens[1] == "->") {
                circuit[tokens[2]] = [tokens, &circuit, &cache] {
                    return calculate_wire(tokens[0], circuit, cache);
                };
            } else if (tokens[1] == "AND") {
                circuit[tokens[4]] = [tokens, &circuit, &cache] {
                    return calculate_wire(tokens[0], circuit, cache) & calculate_wire(tokens[2], circuit, cache);
                };
            }
        }
        file.close();

        for (const auto& wire : circuit) {
            cout << wire.first << ": " << calculate_wire(wire.first, circuit, cache) << endl;
        }
    } else {
        cerr << "Unable to open the input file." << endl;
    }

    return 0;
}
