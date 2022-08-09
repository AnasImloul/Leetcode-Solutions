class Solution:
    def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
        result = []
        for idx in range(len(s)):
            count, row, col = 0, startPos[0],startPos[1]
            while  idx < len(s):
                if s[idx] == 'D':
                    row += 1
                    if row >= n:
                        break
                    count += 1
                elif s[idx] == 'U':
                    row -= 1
                    if row < 0:
                        break
                    count += 1
                elif s[idx] == 'R':
                    col += 1
                    if col >= n:
                        break
                    count += 1
                else:
                    col -= 1
                    if col < 0:
                        break
                    count += 1
                idx += 1
            result.append(count)
        return result
