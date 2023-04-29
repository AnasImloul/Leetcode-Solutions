class Solution:

    def __init__(self, nums: List[int]):
        #self.nums = nums
        #create a hash of values with their list of indices
        self.map = defaultdict(list)
        for i,v in enumerate(nums):
            self.map[v].append(i)
        

    def pick(self, target: int) -> int:
        return random.sample(self.map[target],1)[0]
        '''
        reservoir = 0
        count = 0
        for i in range(len(self.nums)):
            if self.nums[i] == target:
                count+=1
                if random.random() < 1/count:
                    reservoir = i
        return reservoir

        
        samp = []
        for i in range(len(self.nums)):
            if self.nums[i] == target:
                samp.append(i)
        return (random.sample(samp,1))[0]
        '''
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)