import random 

class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def reset(self) -> List[int]:  
        return self.nums

    def shuffle(self) -> List[int]:
        shuffled_array = self.nums.copy()
        # randomly generates the idx of the element that'll be the ith element of the array 
        for i in range(len(self.nums) - 1, 0, -1):
            idx = random.randint(0, i)
            shuffled_array[i], shuffled_array[idx] = shuffled_array[idx], shuffled_array[i]
        return shuffled_array