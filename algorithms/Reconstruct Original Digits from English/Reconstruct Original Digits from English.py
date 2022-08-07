class Solution:
    def originalDigits(self, s: str) -> str:
        cnt = collections.Counter(s)
        
        res = [0 for _ in range(10)]
        
        res[0] = cnt['z']
        res[2] = cnt['w']
        res[4] = cnt['u']
        res[6] = cnt['x']
        res[8] = cnt['g']
        
        res[1] = cnt['o'] - (res[0] + res[2] + res[4])
        res[3] = cnt['t'] - (res[2] + res[8])
        res[5] = cnt['f'] - res[4]
        res[7] = cnt['s'] - res[6]
        res[9] = cnt['i'] - (res[5] + res[6] + res[8])
        
        return ''.join(str(i)*f for i, f in enumerate(res))
