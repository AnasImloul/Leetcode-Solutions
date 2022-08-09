class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        
      
        hashmap1 = {}
        hashmap2 = {}
        common = {}
        for i in range(len(list1)):
            
            hashmap1[list1[i]] = i 
            
            
        for j in range(len(list2)):
            hashmap2[list2[j]] = j 
            
     
        
        for i in hashmap1:
            
            if i in hashmap2:
                print(1)
                common[i] = hashmap1[i] + hashmap2[i]
                
        
        common = list(common.items())
        
        answer =[]
        minimum = float("inf")
        
        for  i in range(0,len(common)):
            
            if common[i][1] < minimum:
                minimum = common[i][1]
                
        for i in range(len(common)):
            
            if common[i][1] == minimum:
                answer.append(common[i][0])
        
        return answer
                
        
       
