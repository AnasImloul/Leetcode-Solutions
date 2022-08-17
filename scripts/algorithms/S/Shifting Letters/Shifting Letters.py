class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        n = len(s)
        nums = []
        sums = 0
        for i in shifts[::-1]:
            sums = (sums+i)%26
            nums.append(sums)
        nums = nums[::-1]
        
        res = ''
        for i, ch in enumerate(s):
            val = ord(s[i]) + nums[i]
            while val > 122:
                val -= 26
            res += chr(val)
        
        return res