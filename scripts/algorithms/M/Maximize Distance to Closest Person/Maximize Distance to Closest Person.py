class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        # strategy is greedy solution:
        # calculate local maximum for each interval: (b-a)//2
        # then take max of local maximums
        # the solution is O(n)
        # I find this solution clear, but uses 5 passes
        
        # get all the occupied seat nums
        seat_nums = [ix for ix, val in enumerate(seats) if val == 1]
        
        # check the ends
        left_max, right_max = min(seat_nums), len(seats)-max(seat_nums)-1
        
        # calculate max distance for each gap
        dists = [(y-x)//2 for x, y in zip(seat_nums, seat_nums[1:])]
        
        # take max of sitting on either end + each gap
        return max([left_max, right_max, *dists])
