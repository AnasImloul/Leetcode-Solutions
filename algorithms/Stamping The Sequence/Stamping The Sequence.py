class Solution:
    def movesToStamp(self, S: str, T: str) -> List[int]:
        if S == T: return [0]
        S, T = list(S), list(T)
        slen, tlen = len(S), len(T) - len(S) + 1
        ans, tdiff, sdiff = [], True, True
        while tdiff:
            tdiff = False
            for i in range(tlen):
                sdiff = False
                for j in range(slen):
                    if T[i+j] == "*": continue
                    if T[i+j] != S[j]: break
                    sdiff = True
                else: 
                    if sdiff:
                        tdiff = True
                        for j in range(i, i + slen): T[j] = "*"
                        ans.append(i)
        for i in range(len(T)):
            if T[i] != "*": return []
        return reversed(ans)
