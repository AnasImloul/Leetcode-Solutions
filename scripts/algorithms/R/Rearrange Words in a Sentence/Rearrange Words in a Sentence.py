// Runtime: 40 ms (Top 89.61%) | Memory: 19.60 MB (Top 55.06%)

class Solution:
    def arrangeWords(self, text: str) -> str:
        a = []
        for x in text.split(" "):
            a.append(x.lower())
        return " ".join(sorted(a, key=len)).capitalize()
