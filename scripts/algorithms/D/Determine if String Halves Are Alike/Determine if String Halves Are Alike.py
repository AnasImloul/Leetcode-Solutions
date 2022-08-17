vowels = "aeiouAEIOU"

class Solution:
    def halvesAreAlike(self, S: str) -> bool:
        mid, ans = len(S) // 2, 0
        for i in range(mid):
            if S[i] in vowels: ans += 1
            if S[mid+i] in vowels: ans -=1
        return ans == 0
