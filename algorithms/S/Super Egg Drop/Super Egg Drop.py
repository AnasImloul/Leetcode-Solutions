class Solution:
    def superEggDrop(self, e: int, f: int) -> int:
        dp = [[-1 for _ in range(e+1)] for _ in range(f+1)]
        
        def solve(floors,eggs):
            
            if eggs==1:
                dp[floors][eggs] = floors
                return floors

            if floors==0:
                dp[floors][eggs] = 0
                return 0
            
            if dp[floors][eggs]==-1:
                
                ans = math.inf
                low = 1
                high = floors
                # Binary Search for the floor where to drop the egg
                while low<=high:
                    mid = (low+high)//2
                    left = solve(mid-1,eggs-1)
                    right = solve(floors-mid,eggs)
                    tmp = 1 + max(left,right)
                    if left < right:
                        low = mid+1
                    else:
                        high = mid-1
                    ans = min(ans,tmp)
              
                dp[floors][eggs] = ans
                
            return dp[floors][eggs]
        
        return solve(f,e)

