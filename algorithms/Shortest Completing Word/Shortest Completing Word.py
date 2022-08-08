class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        newPlate = ''         # modify the licensePlate
        for i in licensePlate:
            if i.isalpha():
                newPlate += i.lower()
                
        c = Counter(newPlate)
        l1 = []         # store (word,len,index)
        for idx,word in enumerate(words):
            if Counter(word) >= c:
                l1.append((word,len(word),idx))
        l1.sort(key = lambda x:(x[1],idx))
        return l1[0][0]
