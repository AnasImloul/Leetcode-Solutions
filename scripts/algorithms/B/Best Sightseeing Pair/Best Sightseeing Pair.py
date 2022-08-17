class Solution:
    """
    Approach: 
    O(n^2) is very straight forward
    For all the possible pairs
    for i in range(n)
      for j in range(i+1, n)
         value[i] = max(value[i], value[i] + value[j] + i - j`)
    
    we can do this problem in O(n) as well
    values = [8, 1, 5, 2, 6]
    max_val = [0, 0, 0, 0, 0]
    max_val[i] = max(max_val[i-1]-1, values[i-1]-1)
    we have to do it once from left side and then from right side
    """
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        left_max_vals = [float('-inf') for _ in range(len(values))]
        right_max_vals = [float('-inf') for _ in range(len(values))]
        
        for i in range(1, len(values)):
            left_max_vals[i] = max(left_max_vals[i-1]-1, values[i-1]-1)
            
        for i in range(len(values)-2, -1, -1):
            right_max_vals[i] = max(right_max_vals[i+1]-1, values[i+1]-1)
        
        max_pair = float('-inf')
        for i in range(len(values)):
            max_pair = max(max_pair, values[i] + max(left_max_vals[i], right_max_vals[i]))
        return max_pair
