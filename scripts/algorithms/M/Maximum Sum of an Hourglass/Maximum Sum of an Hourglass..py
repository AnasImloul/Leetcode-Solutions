// Runtime: 249 ms (Top 27.91%) | Memory: 19.40 MB (Top 36.43%)

class Solution:
    def maxSum(self, x: List[List[int]]) -> int:
        
        # initialize max to 0
        mx = 0
        
        m = len(x)
        n = len(x[0])
        
        # traverse through 
        # rows: m-3 times
        # columns: n-3 times for each row
        for i in range(m-2):
            for j in range(n-2):
                
                # add top horizontal items
                mSum =0
                for k in range(j, j+3):
                    mSum +=x[i][k]
                
                # add bottom horizontal items
                for k in range(j, j+3):
                    mSum +=x[i+2][k]
                
                # add middle element of the hourglass
                mSum += x[i+1][j+1]
                
                # update max if we get new maximum
                if mx < mSum:
                    mx = mSum
        return mx
