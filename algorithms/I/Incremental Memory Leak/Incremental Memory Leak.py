
class Solution:
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        
        inverted = False 
        if memory2>memory1:
            memory2, memory1 = memory1, memory2
            inverted = True 

		#Compute the number of steps in first stage - 1
        i_start = solve_quadratic(1,2*(memory1-memory2))
        
		#Memory1 after the end of first stage is computed using the sum of arithmetic sequence
        memory1-= i_start*(i_start+1)//2
		
		if memory1 == memory2: #Special case (if we end up with equal numbers after stage - 1 - undo inversion)
            inverted = False 
       
        #Compute number of steps in stage - 2
        n_end = solve_quadratic((i_start+1), memory2)
        
		#Compute sums of respective arithmetic sequences
        i_end_1 = i_start - 1 + 2*n_end
        i_end_2 = i_start + 2*n_end
        
        sum1 = n_end * (i_start+1 + i_end_1)//2
        sum2 = n_end * (i_start+2 + i_end_2)//2
        
		#Compute updated memories 
        memory1-=sum1
        memory2-=sum2
        
        full_cnt=2*n_end+i_start
        
        if memory1>=i_end_2+1: #If we can still make one removal from the first stick - perform it.
            memory1-=(i_end_2+1)
            full_cnt+=1
            
        return [full_cnt+1, memory2, memory1] if inverted else [full_cnt+1, memory1, memory2]
            
		 ```