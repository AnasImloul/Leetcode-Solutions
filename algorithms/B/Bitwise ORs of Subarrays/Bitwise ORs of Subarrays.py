class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        
        
        ans=set(arr)
        
        # each element is a subarry
        
        
        one = set()
        
        # to get the ans for the subarray of  size >1
        # starting from 0th element to the ending element
        
        
        one.add(arr[0])
        
        for i in  range(1,len(arr)):
            
            two=set()
            
            for j in one:
                
                two.add(j |  arr[i])
                
                # subarray from the element in one set to the current ele(i th one)
                
                ans.add(j| arr[i])
                
            
            two.add(arr[i])
            
            # adding curr element to set two so that from next iteration we can take sub array starting from curr element 
            
            one = two
            
        return len(ans)
        
