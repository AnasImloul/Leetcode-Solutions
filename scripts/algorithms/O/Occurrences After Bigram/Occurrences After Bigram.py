class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        pattern = r"(?<=\b" + first +" " + second + r" )[a-z]*"
        txt = re.findall(pattern,text)
        return txt