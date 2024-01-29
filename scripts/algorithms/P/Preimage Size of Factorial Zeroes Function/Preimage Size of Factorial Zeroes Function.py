// Runtime: 30 ms (Top 93.33%) | Memory: 16.50 MB (Top 82.96%)

class Solution:
    def preimageSizeFZF(self, k: int) -> int:  

        def atMost_k(k: int)-> int:

            left, right = 0, 5*k + 4

            while left <= right:
                mid = (left+right)//2
                count, n = 0, mid

                while n:
                    n//= 5
                    count+= n

                if count <= k: left = mid + 1
                else: right = mid - 1

            return right

        
        return atMost_k(k) - atMost_k(k-1)
