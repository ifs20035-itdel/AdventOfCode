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

    # print(len(visited_houses))
    return visited_houses

f = open("input.txt", "r")
input = f.read()

# 2nd part
santa = ""
robo_santa = ""
for i in range(len(input)):
    if i%2==0:
        santa+=input[i]
    else:
        robo_santa+=input[i]

# print the merged set of the 2 function(i.e: count_houses()) then return the size of the set
print(len(count_houses(santa).union(count_houses(robo_santa))))