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

# Test cases
test1 = ">"
test2 = "^>v<"
test3 = "^v^v^v^v^v"

count_houses(test1), count_houses(test2), count_houses(test3)
