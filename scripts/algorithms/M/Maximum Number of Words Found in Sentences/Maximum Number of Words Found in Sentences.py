// Runtime: 43 ms (Top 84.42%) | Memory: 16.70 MB (Top 56.32%)

class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        mx=0
        for i in sentences:
            c=i.split()
            if len(c)>mx:
                mx=len(c)
        return mx
		
