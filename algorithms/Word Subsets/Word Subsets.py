class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        result = []
        tempDict = Counter()
        for w in words2:
            tempDict |= Counter(w)
        print(tempDict)
        
        for w in words1:
            if not tempDict - Counter(w):
                result.append(w)
        return result
