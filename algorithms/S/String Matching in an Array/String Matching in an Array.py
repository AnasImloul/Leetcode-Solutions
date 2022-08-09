class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans=set()
        l=len(words)
        for i in range(l):
            for j in range(l):
                if (words[i] in words[j]) & (i!=j):
                    ans.add(words[i])
        return ans
