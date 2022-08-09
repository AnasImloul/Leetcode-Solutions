class Solution:  
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        overlay_arr = [0] * (2*limit+2)
        for i in range(n//2):
            left_boundary = min(nums[i], nums[n-1-i]) + 1
            no_move_value = nums[i] + nums[n-1-i]
            right_boundary = max(nums[i], nums[n-1-i]) + limit
            overlay_arr[left_boundary] -= 1
            overlay_arr[no_move_value] -= 1
            overlay_arr[no_move_value+1] += 1
            overlay_arr[right_boundary+1] += 1
        curr_moves = n   #initial assumption of two moves for each pair
        res = float("inf")
		# start Sweeping
        for i in range(2, 2*limit+1):
            curr_moves += overlay_arr[i]
            res = min(res, curr_moves)
        return res
