class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        binary = []
        final = []
        arr.sort()
        for i in arr:
            binary.append(bin(i).count("1"))
        for i,j in zip(arr,binary):
            final.append((i,j))
        z = sorted(final, key=lambda x:x[1])
        
        ls = []
        for k in z:
            ls.append(k[0])
        
        return ls
