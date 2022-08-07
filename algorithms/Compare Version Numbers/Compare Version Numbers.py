class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1 = list(map(int, version1.split(".")))
        version2 = list(map(int, version2.split(".")))
        while version1 and not version1[-1]: version1.pop()
        while version2 and not version2[-1]: version2.pop()
        if version1 < version2: return -1
        if version1 > version2: return 1
        return 0