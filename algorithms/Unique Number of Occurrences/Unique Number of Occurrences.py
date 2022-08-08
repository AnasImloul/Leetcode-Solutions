class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
		# defining dictionary
        occ = dict()
        
		# adding elements with their counts in dictionary
        for element in arr:
            if element not in occ:
                occ[element] = 0
            else:
                occ[element] += 1
        
		# list of count of elements
        values = list(occ.values())
		# Unique count
        unique = set(values)
        
        if len(values) == len(unique):
            return True
        else:
            return False
