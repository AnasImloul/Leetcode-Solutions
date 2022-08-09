class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        n = len(arr)
        count_one = arr.count(1)
        if count_one == 0: return [0,n-1]
        if count_one % 3!= 0: return [-1,-1]
        target_ones = count_one // 3
        breaks = []
        one_count = 0
        for i , bit in enumerate(arr):
            if bit ==1 :
                one_count +=1
                if one_count in [1,target_ones+1,2*target_ones+1]:breaks.append(i)   
                if one_count in [target_ones,2*target_ones,3*target_ones]:breaks.append(i)
        i1,j1,i2,j2,i3,j3 = breaks
        
        if not arr[i1:j1+1] == arr[i2:j2+1] == arr[i3:j3+1]:return [-1,-1]
        
        trailing_zeroes_left  = i2 - j1 - 1
        trailing_zeroes_mid   = i3 - j2 - 1
        trailing_zeroes_right = n -  j3 - 1
        if trailing_zeroes_right > min(trailing_zeroes_left,trailing_zeroes_mid):return [-1,-1]
        j1 += trailing_zeroes_right
        j2 += trailing_zeroes_right
        return [j1,j2+1]
    
