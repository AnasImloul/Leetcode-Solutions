    def solveEquation(self, equation: str) -> str:
    """ O(N)TS """
    x, y, p = 0, 0, 1
    for i in re.finditer(r"=|[+-]?\d*x|[+-]?\d+", equation):
        g = i.group()
        if g == '=':
            p = -1
        elif g[-1] == 'x':
            x += p * int(g.replace('x', '1' if len(g) == 1 or not g[-2].isdigit() else ''))
        else:
            y += -p * int(g)

    if x == 0 == y:
        return 'Infinite solutions'
    elif x == 0:
        return "No solution"
    return f'x={y // x}'