class Solution:
    def minOperations(self, logs: List[str]) -> int:
        m='../'
        r='./'
		#create an empty stack
        stk=[]
		#iterate through the list
        for i in logs:
			#if Move to the parent folder (../) operator occurs and stack is not empty, pop element from stack
            if(i==m):
                if(len(stk)>0):
                    stk.pop()
			#else if Remain in the same folder (./) operator occurs, do nothing and move to next element in list
            elif(i==r):
                continue
			#else add element to the stack
            else:
                stk.append(i)
		#now return the size of the stack which would be the minimum number of operations needed to go back to the main folder
        return(len(stk))
		```