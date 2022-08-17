class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        arr = [0 for _ in range(2*k+1)]
        for pos, numOfFruit in fruits:
            if pos < startPos-k or pos > startPos+k:
                continue
            arr[pos-(startPos-k)] += numOfFruit
        
        left, right = sum(arr[:k+1]), sum(arr[k:])
        maxSeen = max(left, right)
        
        turn = 1                            # turning point
        for i in range(2, k+1, 2):
            left = left-arr[i-2]-arr[i-1]+arr[k+turn]
            right = right-arr[~(i-2)]-arr[~(i-1)]+arr[k-turn]
            maxSeen = max(maxSeen, left, right)
            turn += 1
        
        return maxSeen
