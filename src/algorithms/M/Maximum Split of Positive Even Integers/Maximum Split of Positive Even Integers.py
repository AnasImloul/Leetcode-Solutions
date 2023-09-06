# Runtime: 344 ms (Top 92.9%) | Memory: 28.91 MB (Top 71.1%)

class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        arr = []
        if finalSum % 2 == 0: # If finalSum is odd then we cannot ever divide it with the given conditions
            a, i = finalSum // 2, 1 # a is the number of 2's and i is the number of 2's that we will use to form a even number in the current iteration
            while i <= a: # Till we have sufficient number of 2's available
                arr.append(2*i) # Join the i number of 2's to form a even number
                a -= i # Number of 2's remaining reduces by i
                i += 1 # Number of 2's required in next itertation increases by 1
            s = sum(arr)
            arr[-1] += finalSum - s # This is done if their were still some 2's remaining that could not form a number due to insufficient count, then we add the remaining 2's into the last number.
        return arr