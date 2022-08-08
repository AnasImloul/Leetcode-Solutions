class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        sorted_products = sorted(products)
        res = []
        prefix = ''
        for letter in searchWord:
            prefix += letter
            words = []
            for product in sorted_products:
                if len(words) == 3:
                    break
                if product.startswith(prefix):
                    words.append(product)
            res.append(words)        
        return res
