class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs)
        col_size = len(strs[0])
        # a b c d e f g h i j k l m n o p q r s t u v w x y z
        
        i = 0
        ans = 0
        
        def getRemoved(idx):
             # removing the idx column 
            for x in range(n):           
                strs[x] = strs[x][:idx] + strs[x][idx+1:]
        
        while i < col_size:
            tmp = strs[0][:i+1]
            flag = True
            similar = False
            
            for j in range(1,n):                 
                if  strs[j][:i+1] < tmp :
                    # previous element is larger ( unsorted )
                    flag = False
                    break
                
                elif strs[j][:i+1] > tmp : 
                    # previous element is smaller ( sorted )
                    tmp = strs[j][:i+1]
                
                else:
                    # previous element is equal ( not clear )
                    tmp = strs[j][:i+1]
                    similar = True
            
            if flag == True and similar == False:
                # all are sorted and we are ready to return ans
                return ans
            
            elif flag == True and similar == True:
                # all are sorted but can't be decided for further columns. check for next col
                i += 1
            
            elif flag == False:
                # unsorted column = removal
                getRemoved(i)
                # increment the answer and since we removed i th col decrement col_size
                ans += 1
                col_size -= 1
        
        return ans
