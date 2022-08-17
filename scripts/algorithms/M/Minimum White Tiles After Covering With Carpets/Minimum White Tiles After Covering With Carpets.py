class Solution:
    def minimumWhiteTiles(self, floor: str, numCarpets: int, carpetLen: int) -> int:
		n = len(floor)
		#Using memo table to store predefined computations
        memo = [[-1 for x in range(numCarpets+1)] for x in range(len(floor)+1)] 
        def solve(N,numCarpets):
			#Base Case
            if N>=n:
                return 0
			#If calculated previously use that solution
            if memo[N][numCarpets]!=-1:
                return memo[N][numCarpets]
				
            used = 0 # If you use the carpet
            notused = 0 # If you donot use the carpet
			
            if floor[N]=='1': # We might use the carpet in this part
                if numCarpets>0: #Whether we even have some carpets or not
				    """
					Optimization Part
					We are finding the number of ones present in this part of the floor.
					prefix[lastInd] - Number of ones till lastInd
					prefix[N] - Number of ones till Nth Index.
					
					Their difference gives us how many ones present between the two.
				    """
                    lastInd = min(N+carpetLen,len(floor)) 
                    ans = prefix[lastInd] - prefix[N]
                    
					"""
					Find the max if we use or donot use carpet at this index
					If we do we add  --- ans and decrement remaining carpets
					else we donot
					"""
                    used = max(solve(N+carpetLen,numCarpets-1)+ans,solve(N+1,numCarpets))
                            
                else:
                    used = 0
            
            else:
			#If we donot use the carpet although I feel this might be redundant code
                notused = solve(N+1,numCarpets)
            
			#Using max function to find the number of white tiles removed
            memo[N][numCarpets] = max(used,notused)
            return memo[N][numCarpets]
		
		#Total White tiles
        ones = 0
        for x in floor:
            if x == '1':
                ones+=1
        
		#Using Prefix array to store number of ones till i th index
        prefix = [0]*(n+1)
        for i in range(1,n+1):
            if floor[i-1]=='1':
                prefix[i] = prefix[i-1]+1
            else:
                prefix[i] = prefix[i-1]
				
       
        removed = solve(0,numCarpets)
        
        return ones-removed
