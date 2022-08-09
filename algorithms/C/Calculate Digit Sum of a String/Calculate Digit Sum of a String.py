class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            set_3 = [s[i:i+k] for i in range(0, len(s), k)]
            s = ''
            for e in set_3:
                val = 0
                for n in e:
                    val += int(n)
                s += str(val)
        return s
