# Runtime: 42 ms (Top 78.1%) | Memory: 16.35 MB (Top 47.9%)

class Solution:
    def longestString(self, x: int, y: int, z: int) -> int:
        #"AB" can be placed any where in the answer ,count="AB"*2
        count=z*2

        #take pair of "AA" and "BB" then concatinate at the end like "ABAB"+"AABBAABBAABB"="ABABAABBAABBAABB"
        n=min(x,y)
        count+=n*4 
        x-=n
        y-=n
        #now check if any one of  "AA" or "BB" is left or not and if "AA" is left then put it in the end. else put in the start
        if x>0 or y>0:
            count+=2
        return count

