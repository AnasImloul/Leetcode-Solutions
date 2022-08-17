class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack=[]
        i=0
        for num in pushed:
            stack.append(num) #we are pushing the number to the stack
            while  len(stack) >0 and stack[len(stack)-1] == popped[i] :
                #if the last element of the stack is equal to the popped element
                stack.pop()
                i+=1 #we are incrementing i
        return True if len(stack) ==0 else False
		
