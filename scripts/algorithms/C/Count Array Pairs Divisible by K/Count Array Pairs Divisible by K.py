class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        counter = Counter() #hashmap dicitionary of python
        ans = 0
        n = len(nums)
        
        for i in range(n):
            x = math.gcd(k,nums[i]) #ex: 10 = k and we have nums[i] as 12 so gcd will be 2
            want = k // x #what do we want from upper ex: we need 5
            for num in counter:
                if num % want == 0: #so if we find a number that is divisible by 5 then we can multiply it to 12 and make it a factor of 10 for ex we find 20 so it will be 240 which is divisible by 10 hence we will add it to answer
                    ans += counter[num] #we are adding the freq as we can find no of numbers that have same factor
            counter[x] += 1 #here we are increasing the freq of 2 so that if we find 5 next time we can add these to the answer
        return ans
		```