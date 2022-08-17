class Solution:
    def reformatNumber(self, number: str) -> str:
        s = number.replace(" ", "").replace("-", "")
        pieces = list()
        while s:
            if len(s) == 2:
                pieces.append(s)
                break
            elif len(s) == 4:
                pieces.append(s[:2])
                pieces.append(s[2:])
                break
            else:
                pieces.append(s[:3])
                s = s[3:]
        return "-".join(pieces)
