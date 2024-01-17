// Runtime: 724 ms (Top 91.98%) | Memory: 17.70 MB (Top 44.11%)

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        numCoins = len(coins)
        
        # Values in this array equal the number of coins needed to achieve the cost of the index
        minCoins = [amount + 1] * (amount + 1)
        minCoins[0] = 0
        
        # Loop through every needed amount
        for i in range(amount + 1):
            # Loop through every coin value
            for coin in coins:
                # Check that the coin is not bigger than the current amount
                if coin <= i:
                    # minCoins[i]: number of coins needed to make amount i
                    # minCoins[i-coin]: number of coins needed to make the amount before adding 
                    #                   the current coin to it (+1 to add the current coin)
                    minCoins[i] = min(minCoins[i], minCoins[i-coin] + 1)
        
        # Check if any combination of coins was found to create the amount
        if minCoins[amount] == amount + 1:
            return -1
        
        # Return the optimal number of coins to create the amount
        return minCoins[amount]
