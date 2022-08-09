class Solution:
    def sortSentence(self, s: str) -> str:
        
        x = s.split()
        dic = {}
        for i in x :
            dic[i[-1]] = i[:-1]
        return ' '.join([dic[j] for j in sorted(dic)])
