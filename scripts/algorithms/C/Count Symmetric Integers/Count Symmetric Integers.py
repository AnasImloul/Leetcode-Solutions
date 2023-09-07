# Runtime: 1302 ms (Top 45.3%) | Memory: 13.61 MB (Top 27.6%)

class Solution(object):
    def countSymmetricIntegers(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        all = 0
        # This counts the total number of symmetrical integers
        for i in range(low, high+1):
            # Loop through every possible number
            i = str(i)
            # Convert the number to a string
            if len(i) % 2 == 0:
                # Check that there is an even number of digits
                if sum([int(i[x])  for x in range(0, len(i)/2)]) == sum([int(i[x]) for x in range(len(i)/2, len(i))]):
                    # Compare the first and last half of the string
                    all += 1
        return all
        # Return the final answer
        