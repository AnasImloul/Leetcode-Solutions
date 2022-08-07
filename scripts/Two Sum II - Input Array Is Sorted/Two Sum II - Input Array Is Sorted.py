class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        s=0
        e=len(numbers)-1
        while s<e:
            sumi = numbers[s]+numbers[e]
            if(sumi==target):
                return [s+1, e+1]
                
            elif(sumi<target):
                s+=1
            
            else:
                e-=1
