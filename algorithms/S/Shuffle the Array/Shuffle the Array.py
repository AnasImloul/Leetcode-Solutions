'''
First of all, I'm making a few tuples  using zip function.
Then extracting every created tuple. (for tup in zip())
After that, I can take numbers from the extracted tuples, in order to add them to a list and return. (for number in tup)
'''
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return [number for tup in zip(nums[:n], nums[n:]) for number in tup]
