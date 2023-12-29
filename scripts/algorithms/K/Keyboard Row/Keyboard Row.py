// Runtime: 34 ms (Top 77.79%) | Memory: 17.40 MB (Top 7.9%)

class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        #
        set1 = {'q','w','e','r','t','y','u','i','o','p'}
        set2 = {'a','s','d','f','g','h','j','k','l'}
        set3 = {'z','x','c','v','b','n','m'}
        
        res = []
        for i in words:
            wordset = set(i.lower())
            if (wordset&set1 == wordset) or (wordset&set2 == wordset) or (wordset&set3 == wordset):
                res.append(i)
        return res
