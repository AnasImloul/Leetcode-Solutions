class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        
        //final answer
        new = []
        carry = 0
        
		//make arrays length equal 
        if len(arr1) < len(arr2):
            diff = len(arr2) - len(arr1)
            arr1 = ([0] * diff) + arr1
        
        if len(arr1) > len(arr2):
            diff = len(arr1) - len(arr2)
            arr2 = ([0] * diff) + arr2
            
            
        
        //add values at every index and set carry and new value appropriately
        while arr1 and arr2:
            
            top = arr1.pop()
            down = arr2.pop()
            
            add = top + down + carry
            
            if add == -1:
                new = [1] + new
                carry = 1
            
            elif add == 1 or add == 0:
                new =  [add] + new
                carry = 0
                
            elif add == 2:
                new = [0] + new
                carry = -1
            
            else:
                new = [1] + new
                carry = -1
                
         // if carry -1 add 1 1 since -1 is 11 in negabinary
        if carry == -1:
            new = [1,1] + new
            
		//remove any leading zeros
        while new[0] == 0 and len(new) >1:
            new = new[1:]
            
        return new
