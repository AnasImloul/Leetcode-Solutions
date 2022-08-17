class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        l, i, N = [], 0, len(s)
        while i<N:
            l.append(s[i:i+k])
            i += k
        last = l[-1]
        if(len(last)<k):
            l[-1] += fill*(k-len(last))
        return l
