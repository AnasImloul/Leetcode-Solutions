class Solution:
    def compareVersion(self, v1: str, v2: str) -> int:
        v1, v2 = list(map(int, v1.split('.'))), list(map(int, v2.split('.')))  
        for rev1, rev2 in zip_longest(v1, v2, fillvalue=0):
            if rev1 == rev2:
                continue

            return -1 if rev1 < rev2 else 1 

        return 0