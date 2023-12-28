// Runtime: 44 ms (Top 40.74%) | Memory: 17.40 MB (Top 5.82%)

class Solution:
    def oddString(self, words: List[str]) -> str:
        hashmap = defaultdict(list)
        for w in words:
            difference = []
            for i in range(1,len(w)):
                difference.append(ord(w[i])-ord(w[i-1]))
            hashmap[tuple(difference)].append(w)
        for k,a in hashmap.items():
            if len(a) == 1:
                return a[0]
