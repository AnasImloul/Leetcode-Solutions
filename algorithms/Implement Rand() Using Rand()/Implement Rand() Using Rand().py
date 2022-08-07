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