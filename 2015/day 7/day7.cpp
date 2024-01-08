#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

// Define a struct to represent circuit operations
struct Operation {
    vector<string> inputs;
    string type;
    string output;
};

// Function to calculate wire value
unsigned short calculate_wire(const string& wire, unordered_map<string, Operation>& circuit, unordered_map<string, unsigned short>& cache) {
    if (isdigit(wire[0])) {
        // If the wire is a numeric value, convert it to an integer
        return stoi(wire);
    }

    if (cache.find(wire) == cache.end()) {
        const Operation& operation = circuit[wire];
        if (operation.type == "DIRECT") {
            // Direct assignment
            cache[wire] = calculate_wire(operation.inputs[0], circuit, cache);
        } else if (operation.type == "NOT") {
            // Bitwise NOT operation
            cache[wire] = ~calculate_wire(operation.inputs[0], circuit, cache) & 0xFFFF;
        } else if (operation.type == "AND") {
            // Bitwise AND operation
            cache[wire] = calculate_wire(operation.inputs[0], circuit, cache) & calculate_wire(operation.inputs[1], circuit, cache);
        } else if (operation.type == "OR") {
            // Bitwise OR operation
            cache[wire] = calculate_wire(operation.inputs[0], circuit, cache) | calculate_wire(operation.inputs[1], circuit, cache);
        } else if (operation.type == "LSHIFT") {
            // Left shift operation
            cache[wire] = calculate_wire(operation.inputs[0], circuit, cache) << stoi(operation.inputs[1]);
        } else if (operation.type == "RSHIFT") {
            // Right shift operation
            cache[wire] = calculate_wire(operation.inputs[0], circuit, cache) >> stoi(operation.inputs[1]);
        }
    }

    return cache[wire];
}

int main() {
    unordered_map<string, Operation> circuit;
    unordered_map<string, unsigned short> cache;

    ifstream input_file("input.txt");
    string line;

    while (getline(input_file, line)) {
        istringstream iss(line);
        string word, wire;
        Operation operation;

        // Parse the line into parts
        while (iss >> word) {
            if (word == "->") {
                break;
            }
            operation.inputs.push_back(word);
        }

        iss >> wire; // Get the wire name

        if (operation.inputs.size() == 1) {
            operation.type = "DIRECT";
        } else if (operation.inputs[0] == "NOT") {
            operation.type = "NOT";
        } else if (operation.inputs[1] == "AND") {
            operation.type = "AND";
        } else if (operation.inputs[1] == "OR") {
            operation.type = "OR";
        } else if (operation.inputs[1] == "LSHIFT") {
            operation.type = "LSHIFT";
        } else if (operation.inputs[1] == "RSHIFT") {
            operation.type = "RSHIFT";
        }

        operation.output = wire;
        circuit[wire] = operation;
    }

    // Calculate the values for each wire
    for (const auto& entry : circuit) {
        const string& wire = entry.first;
        cout << wire << ": " << calculate_wire(wire, circuit, cache) << endl;
    }

    return 0;
}
