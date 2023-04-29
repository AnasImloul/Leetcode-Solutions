class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        l = 1
        r = int(1e9)
        ans = 0

        while l<=r:
            mid = (l+r)//2
            total = 0

            # add left numbers
            if mid>=index+1:
                first = mid-index
                size = index+1
                total += first*size + size*(size-1)/2
            else:
                total += mid*(mid+1)/2
                total += index+1-mid


            # add right numbers
            size = n-index
            if mid >= size:
                last = mid - (n-index-1)
                total += last*size + size*(size-1)/2
            else:
                total += mid*(mid+1)/2
                total += (size-mid)   

            # deduct mid because it was added twice 
            total -= mid
            
            if total <= maxSum:
                ans = max(ans, mid)
                l = mid+1
            else:
                r = mid-1

        return ans