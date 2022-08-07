class Solution:
    def isNumber(self, s: str) -> bool:
        if s == "inf" or s == "-inf" or s == "+inf" or s == "Infinity" or s == "-Infinity" or s == "+Infinity":
            return False
        try:
            float(s)
        except (Exception):
            return False
        return True
