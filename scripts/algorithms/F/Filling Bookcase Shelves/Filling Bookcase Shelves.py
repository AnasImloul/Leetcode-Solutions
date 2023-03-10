class Solution:
    def minHeightShelves(self, books, shelf_width: int) -> int:
        n, dp = len(books), [float('inf')] * (len(books)+1)
        dp[0] = 0

        for i in range(1, n+1):
            max_width, max_height, j = shelf_width, 0, i - 1
            
            while j >= 0 and max_width - books[j][0] >= 0:
                max_width -= books[j][0]
                max_height = max(max_height, books[j][1])
                dp[i] = max_height
                j -= 1

            if j >= 0 and max_width - books[j][0] < 0:
                j = i - 1
                dp[i] = float('inf')
                width, height = 0, 0
                while j >= 0 and width + books[j][0] <= shelf_width:
                    width = width + books[j][0]
                    height = max(books[j][1], height)
                    dp[i] = min(dp[i], height + dp[j])
                    j -= 1

        return dp[n]
