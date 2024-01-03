def count_houses(directions):
    # Starting position
    x, y = 0, 0
    # Set to keep track of visited houses
    visited_houses = {(x, y)}

    for move in directions:
        if move == '^':
            y += 1
        elif move == 'v':
            y -= 1
        elif move == '>':
            x += 1
        elif move == '<':
            x -= 1
        # Add the new position to the set
        visited_houses.add((x, y))

    print(len(visited_houses))

f = open("input.txt", "r")
count_houses(f.read())