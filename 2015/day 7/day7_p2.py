def get_value(wire, circuit, cache):
    if wire.isdigit():
        return int(wire)
    if wire not in cache:
        operation = circuit[wire]
        if "AND" in operation:
            cache[wire] = get_value(operation[0], circuit, cache) & get_value(operation[2], circuit, cache)
        elif "OR" in operation:
            cache[wire] = get_value(operation[0], circuit, cache) | get_value(operation[2], circuit, cache)
        elif "LSHIFT" in operation:
            cache[wire] = get_value(operation[0], circuit, cache) << int(operation[2])
        elif "RSHIFT" in operation:
            cache[wire] = get_value(operation[0], circuit, cache) >> int(operation[2])
        elif "NOT" in operation:
            cache[wire] = ~get_value(operation[1], circuit, cache) & 0xFFFF
        else:
            cache[wire] = get_value(operation[0], circuit, cache)
    return cache[wire]


def main():
    circuit = {}
    cache = {}

    # Read instructions from a file
    with open("input.txt", "r") as f:
        lines = f.read().split('\n')

    # Store the original instructions to reset the circuit later
    original_circuit = circuit.copy()

    for line in lines:
        parts = line.split()
        if "->" in line:
            circuit[parts[-1]] = parts[:-2]

    # Calculate the original value of wire "a"
    original_a_value = get_value("a", circuit, cache)

    # Override wire "b" with the value of wire "a"
    circuit["b"] = [str(original_a_value)]

    # Reset the cache for recalculating wire values
    cache = {}

    # Calculate the new values for all wires
    for wire in circuit:
        get_value(wire, circuit, cache)

    # Print the new value of wire "a"
    new_a_value = get_value("a", circuit, cache)
    print(f"Result: value of 'a' >> {new_a_value}")

    # Reset the circuit to its original state
    circuit = original_circuit
    cache = {}

    # Calculate the values for each wire in the original circuit
    # for wire in circuit:
    #     # print(f"{wire}: {get_value(wire, circuit, cache)}")
    #     if wire == problem:
    #         print(f"{wire}: {get_value(wire, circuit, cache)}")
    #     get_value(wire,circuit, cache)

if __name__ == "__main__":
    main()
