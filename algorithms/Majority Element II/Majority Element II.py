class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        
        #Boyer Moore Voting Algo (As used in ME1 ques) 
        #now we can observe that there cannot be more than two elements occuring more than n//3 times in an array
        #so find two majority elements(me=majority element)
        

        n=len(nums)
        req=n//3  #for an element to be ME required number of times present 

        c1=0 #count 1
        c2=0 #count 2
        me1=None #majority element 1
        me2=None #majority element 2

        for i in nums:
            if i == me1:
                c1+=1

            elif i == me2:
                c2+=1

            elif c1 == 0:
                me1=i
                c1=1

            elif c2 == 0:
                me2=i
                c2=1

            else:
                c1-=1
                c2-=1
        #here we have found our majority elements now check if the found majority element is ME
        # print(me1,me2)

        #check if the found majority element is ME
        c1=0
        c2=0
        for i in nums:
            if i==me1:
                c1+=1
            if i==me2:
                c2+=1
        # print(c1,c2)

        if c1 > req  and c2 > req:

            return [me1,me2]

        elif c1> req :
            return [me1]

        elif c2> req :
            return [me2]

