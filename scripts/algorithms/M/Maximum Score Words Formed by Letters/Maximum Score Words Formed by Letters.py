// Runtime: 61 ms (Top 55.33%) | Memory: 17.40 MB (Top 11.89%)

class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:

        f, ans = lambda x : sum(score[ord(c) - 97] for c in x), 0

        def dfs(words,letters, tally):
            nonlocal ans
            
            for i in range(len(words)):
                cWord=Counter(words[i])
				
                if all(letters[c] >= cWord[c] for c in cWord):
                    dfs(words[i+1:], letters - cWord, tally + f(words[i]))

            ans = max(ans,tally)
            return ans

        return dfs(words, Counter(letters), 0)
