class Solution:
    def candy(self, ratings: List[int]) -> int:
        n=len(ratings)
        temp = [1]*n
        
        for i in range(1,n):
            if(ratings[i]>ratings[i-1]):
                temp[i]=temp[i-1]+1
        if(n>1):
            if(ratings[0]>ratings[1]):
                temp[0]=2
                
            
        for i in range(n-2,-1,-1):
            if(ratings[i]>ratings[i+1] and temp[i]<=temp[i+1]):
                temp[i]=temp[i+1]+1

                
        return sum(temp)
