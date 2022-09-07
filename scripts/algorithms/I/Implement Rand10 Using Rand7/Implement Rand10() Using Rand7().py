# Runtime: 860 ms (Top 14.45%) | Memory: 16.7 MB (Top 77.01%)
class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        x = rand7()
        y = rand7()
        pos = (x - 1) * 7 + y
        if pos > 40:
            return self.rand10()
        return (pos % 10) + 1
        ```