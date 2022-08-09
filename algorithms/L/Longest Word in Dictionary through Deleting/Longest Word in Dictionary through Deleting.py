class Solution:
    def findLongestWord(self, s: str, dictionary: list[str]) -> str:
        solution = ""
        for word in dictionary:
            j = 0
            for i in range(len(s)):
                if s[i] == word[j]:
                    j+=1
                if j == len(word):
                    solution = word if len(word) > len(solution) or len(word) == len(solution) and word < solution  else solution
                    break
        return solution