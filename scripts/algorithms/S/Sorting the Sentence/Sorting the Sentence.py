# Runtime: 68 ms (Top 5.88%) | Memory: 13.7 MB (Top 96.86%)
class Solution:
    def sortSentence(self, s: str) -> str:

        x = s.split()
        dic = {}
        for i in x :
            dic[i[-1]] = i[:-1]
        return ' '.join([dic[j] for j in sorted(dic)])