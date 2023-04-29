class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        fixed = 0

        for i in range(1, len(pref)):
            fixed ^= pref[i - 1]
            pref[i] = fixed ^ pref[i]

        return pref