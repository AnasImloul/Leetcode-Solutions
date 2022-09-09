# Runtime: 82 ms (Top 23.89%) | Memory: 13.9 MB (Top 78.76%)

class Solution:
    def longestDecomposition(self, text: str) -> int:
        left, right = 0, len(text) - 1
        sol, last_left = 0, 0
        a, b = deque(), deque()
        while right > left:
            a.append(text[left])
            b.appendleft(text[right])
            if a == b:
                sol += 2
                last_left = left
                a, b = deque(), deque()
            right -= 1
            left += 1
        if left == right or left > last_left + 1:
            sol += 1
        return max(sol, 1)
