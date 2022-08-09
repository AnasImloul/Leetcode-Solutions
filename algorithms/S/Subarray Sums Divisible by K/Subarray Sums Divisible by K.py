class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        #if two prefix sums produce equal remainder then we got a subarray
        #if si%k==sj%k then (si-sj)%k=si%k-sj%k=0
        #so we store remainders successively also check if this remainder already available if yes increase count of that remainder +1
        #now be careful for -ve remainders as they may cause other result suppose 1 as remainder and -1 as remainder they are not equal according to you right but -1+k which is the positive remainder version of -1 may match a result so always make re``mainder+k if it is negative
        #that's it
        
        prefsum=0
        ans=0
        d={0:1}
        
        for num in nums:
            prefsum+=num
            remainder=prefsum%k
            
            if remainder<0:
                remainder=remainder+k #making positive version of negative remainder
            
            #check if remainder already exst we got a answer
            if remainder in d:
                ans+=d[remainder]
            
            #now time to store this remainder
            if remainder not in d:
                d[remainder]=1
            else:
                d[remainder]+=1
            
            #it took a lot of effort to understand solution from multiple sources
            #lets run and check if it is accepted
        
        return ans
    #yeah passed example test cases
    #yoo passed
	```