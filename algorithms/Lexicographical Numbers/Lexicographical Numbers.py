class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        result = []
        orderDic = {}
        for i in range(1, n + 1):
            strI = str(i)
            level = orderDic
            for char in strI:
                if char not in level:
                    level[char] = {}
                level = level[char]
        self.traverse(orderDic, "", result)
        return result
        
    def traverse(self, dic, temp, result):
        for key in dic:
            result.append(int(temp + key))
            self.traverse(dic[key], temp + key, result)
