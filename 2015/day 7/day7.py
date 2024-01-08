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

def main(problem):
    circuit = {}
    cache = {}

    f = open("input.txt", "r")
    input = f.read()
    lines = input.split('\n')

    for line in lines:
        parts = line.split()
        if "->" in line:
            circuit[parts[-1]] = parts[:-2]

    # Calculate the value of certain input 
    for wire in circuit:
        # print(f"{wire}: {get_value(wire, circuit, cache)}")
        if wire == problem:
            print(f"{wire}: {get_value(wire, circuit, cache)}")
        get_value(wire,circuit, cache)

if __name__ == "__main__":
    certain_value = input("What wire is needed ? \n")
    main(certain_value)

