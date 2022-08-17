class Solution:
    def calPoints(self, ops: List[str]) -> int:
        temp = []
        for i in ops:
            if i!="C" and i!="D" and i!="+":
                temp.append(int(i))
            elif i=="C":
                temp.remove(temp[len(temp)-1])
            elif i=="D":
                temp.append(2*temp[len(temp)-1])
            elif i=="+":
                temp.append(temp[len(temp)-1]+temp[len(temp)-2])
        
        
        return sum(temp)
