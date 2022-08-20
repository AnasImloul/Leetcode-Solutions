# Runtime: 54 ms (Top 48.33%) | Memory: 14.1 MB (Top 96.59%)

from collections import Counter

class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        diffCharactersCount = 0
        diffCharactersInS = []
        diffCharactersInGoal = []
        for i in range(len(s)):
            if s[i] != goal[i]:
                diffCharactersCount += 1
                diffCharactersInS.append(s[i])
                diffCharactersInGoal.append(goal[i])
        if diffCharactersCount == 2:
            # if there are only 2 different characters, then they should be swappable
            if ((diffCharactersInS[0] == diffCharactersInGoal[1]) and (diffCharactersInS[1] == diffCharactersInGoal[0])):
                return True
            return False
        elif diffCharactersCount == 0:
            # if there is atleast one repeating character in the string then its possible for swap
            counts = Counter(s)
            for k,v in counts.items():
                if v > 1:
                    return True
        # if different characters count is not 2 or 0, then it's not possible for the strings to be buddy strings
        return False
