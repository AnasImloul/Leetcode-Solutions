# Runtime: 96 ms (Top 61.23%) | Memory: 14 MB (Top 75.15%)
class Solution:
    def convert(self, s: str, numRows: int) -> str:

        # safety check to not process single row
        if numRows == 1:
            return s

        # safety check to not process strings shorter/equal than numRows
        if len(s) <= numRows:
            return s

        # safety check to not process double rows
        if numRows == 2:
            # slice every other character
            return s[0::2] + s[1::2]

        # list that stores the lines
        # add lines with initial letters
        lines: list[str] = [letter for letter in s[:numRows]]

        # positive direction goes down
        # lines are created, so it's going up
        direction: int = -1

        # track the position at which the letter will be added
        # position after bouncing off, after adding initial lines
        line_index: int = numRows - 2

        # edge indexes
        # 0 can only be reached by going up
        # numRows only by going down
        edges: set[int] = {0, numRows}

        for letter in s[numRows:]:
            # add letter at tracked index position
            lines[line_index] += letter

            # prepare index before next loop iteration
            line_index += direction

            # reaching one of the edges
            if line_index in edges:
                # change direction
                direction = -direction
                # bounce off if bottom edge
                if line_index == numRows:
                    line_index += direction * 2

        return "".join(lines)