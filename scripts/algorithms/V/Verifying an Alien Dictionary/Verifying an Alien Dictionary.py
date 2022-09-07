# Runtime: 74 ms (Top 17.14%) | Memory: 13.7 MB (Top 99.39%)
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order_index = {key:index for index, key in enumerate(order)}

        for i in range(len(words)-1):
           w1,w2 = words[i] , words[i + 1]
           for j in range(len(w1)):
                if j == len(w2):
                    return False
                if w1[j] != w2[j]:
                    if order_index.get(w2[j]) < order_index.get(w1[j]):
                        return False
                    break
        return True