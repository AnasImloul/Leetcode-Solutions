class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        temp = []
        result = []
        x = target[-1]
        for i in range(1,x+1):
            temp.append(i)
        for i in range(len(temp)):
            if temp[i] in target:
                result.append("Push")
            elif temp[i] not in target:
                result.append("Push")
                result.append("Pop")
        return result
