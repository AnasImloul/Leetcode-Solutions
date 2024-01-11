// Runtime: 865 ms (Top 94.12%) | Memory: 32.60 MB (Top 7.84%)

class Solution:
    def maximumBeauty(self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int) -> int:
        
		# move out already completed garden
        already_complete = 0
        temp = []
        for f in flowers:
            if f >= target:
                already_complete += 1
            else:
                temp.append(f)

        max_beauty = 0
        
        flowers = temp
        flowers.sort()
        
        presum = [0] + list(accumulate(flowers))
        N = len(flowers)
        
        dp_arr = []
        
        for i in range(N+1):
            # iterate all index: left part is all partial, right part (>= i) is all complete
            
            # update the dp arr for binary search below
            if i < N:
                dp_arr.append((i+1) * flowers[i] - presum[i+1])
            
            right_sum = presum[-1] - presum[i]
            right_count = N - i
            
            # if can't make the right part all complete, go to next index
            if right_sum + newFlowers < right_count * target:
                continue
            
            # remaining flowers after making right part all complete
            rem_flowers = newFlowers - (right_count * target - right_sum)
            
            # binary search to find the maximum possible min flowers in the left part (named 'min_partial')
            if i == 0:
                min_partial = 0
            else:
                j = min(bisect.bisect_right(dp_arr, rem_flowers) - 1, i-1)
                min_partial = min((rem_flowers + presum[j+1]) // (j+1), target-1)
                 
            complete = right_count + already_complete
            max_beauty = max(max_beauty, complete * full + min_partial * partial)

            
        return max_beauty
