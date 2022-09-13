# Runtime: 111 ms (Top 13.83%) | Memory: 14 MB (Top 12.56%)
class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        x = 0
        for o in operations:
            if '+' in o:
                x += 1
            else:
                x -= 1
        return x