class Solution:
    from collections import defaultdict
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
		
		# The idea here was to create a hashmap of value to weight mapping
        # iterate through items1 and populate the hashmap
		value_weight = defaultdict(int)
        for i, j in items1:
            value_weight[i] = j
		
        # compare values with hashmap and update the weights
		for i, j in items2:
            value_weight[i] += j
			
		# return the hashmap in list format
        ans = []
        for value in sorted(value_weight.keys()):
            ans.append([value, value_weight[value]])
        return ans
