# Runtime: 53 ms (Top 19.4%) | Memory: 16.58 MB (Top 12.8%)

class Solution:
    def captureForts(self, forts: List[int]) -> int:
        i = 0 
        j = i +1
        c = 0
        l = [0]
        while i < len(forts) and j < len(forts):
            if forts[i] == 1:
                while forts[j] == 0 and j < len(forts)-1:
                    c += 1
                    j += 1
                if forts[j] == 1:
                    c = 0
                if forts[j] != -1 :
                    c = 0
                l.append(c)
                c = 0
                i = j 
                j = i + 1
            elif forts[i] == -1: 
                while forts[j] == 0 and j < len(forts)-1:
                    c += 1
                    j += 1
                if forts[j] == -1:
                    c = 0
                if forts[j] != 1:
                    c = 0
                l.append(c)
                c = 0
                i = j
                j = i + 1
            else:
                i += 1
                j = i+1
        print(l)
        return max(l)

        