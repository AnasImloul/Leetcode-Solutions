// Runtime: 78 ms (Top 77.93%) | Memory: 19.60 MB (Top 79.27%)

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        list_ = []
        products.sort()
        for i, c in enumerate(searchWord):
            products = [ p for p in products if len(p) > i and p[i] == c ]
            list_.append(products[:3])
        return list_
