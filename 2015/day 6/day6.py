def count_lit_lights(instructions):
    grid = [[False for _ in range(1000)] for _ in range(1000)]

    def apply_instruction(instruction):
        action, start, end = instruction
        x1, y1 = map(int, start.split(','))
        x2, y2 = map(int, end.split(','))

        for i in range(x1, x2 + 1):
            for j in range(y1, y2 + 1):
                if action == "turn on":
                    grid[i][j] = True
                elif action == "turn off":
                    grid[i][j] = False
                elif action == "toggle":
                    grid[i][j] = not grid[i][j]

    for instruction in instructions:
        apply_instruction(instruction)

    return sum(sum(row) for row in grid)

f = open("input.txt", "r")
input = f.read()
lines = input.split('\n')

instructions = [
    ("turn on", "0,0", "999,999"),
    ("toggle", "0,0", "999,0"),
    ("turn off", "499,499", "500,500")
]

count_lit_lights(lines)
