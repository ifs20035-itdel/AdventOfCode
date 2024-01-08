#include <iostream>
#include <unordered_map>
#include <sstream>
#include <functional>
#include <string>
#include <vector>

unsigned short calculate_wire(const std::string& wire, 
                              std::unordered_map<std::string, std::function<unsigned short()>>& circuit, 
                              std::unordered_map<std::string, unsigned short>& cache) {
    if (isdigit(wire[0])) {
        return static_cast<unsigned short>(std::stoi(wire));
    }

    if (cache.find(wire) == cache.end()) {
        cache[wire] = circuit[wire]();
    }

    return cache[wire];
}

int main() {
    std::unordered_map<std::string, std::function<unsigned short()>> circuit;
    std::unordered_map<std::string, unsigned short> cache;
    std::string line;

    // Replace with actual input
    std::vector<std::string> instructions = {
        "123 -> x",
        "456 -> y",
        "x AND y -> d",
        "x OR y -> e",
        "x LSHIFT 2 -> f",
        "y RSHIFT 2 -> g",
        "NOT x -> h",
        "NOT y -> i"
    };

    for (const auto& instruction : instructions) {
        std::istringstream iss(instruction);
        std::vector<std::string> tokens{std::istream_iterator<std::string>{iss}, 
                                        std::istream_iterator<std::string>{}};

        if (tokens[1] == "->") {
            circuit[tokens[2]] = [tokens, &circuit, &cache] {
                return calculate_wire(tokens[0], circuit, cache);
            };
        } else if (tokens[1] == "AND") {
            circuit[tokens[4]] = [tokens, &circuit, &cache] {
                return calculate_wire(tokens[0], circuit, cache) & calculate_wire(tokens[2], circuit, cache);
            };
        } // Add other operations (OR, LSHIFT, RSHIFT, NOT) here
    }

    // Calculate the values for each wire
    for (const auto& wire : circuit) {
        std::cout << wire.first << ": " << calculate_wire(wire.first, circuit, cache) << std::endl;
    }

    return 0;
}

