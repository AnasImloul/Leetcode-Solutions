class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        left, mid, right=[], [], []

        for itr in nums:
            if itr<pivot:
                left.append(itr)
            elif itr>pivot:
                right.append(itr)                
            else:
                mid.append(itr)
        
        return left+mid+right