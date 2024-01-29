// Runtime: 32 ms (Top 84.42%) | Memory: 16.40 MB (Top 68.29%)

class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        """
        #method 1:
        for i in range(len(word)):
            if word[i]==ch:
                return word[:i+1][::-1]+word[i+1:]
        return word"""
        #method 2:
        l=0
        r=word.find(ch)
        word=list(word)
        while l<r:
            word[l],word[r]=word[r],word[l]
            l+=1
            r-=1
        return "".join(word)
        

                


        

            
