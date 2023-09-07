# Runtime: 114 ms (Top 100.0%) | Memory: 13.51 MB (Top 53.8%)

class Solution(object):
    def squareFreeSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # Find frequency of each value 
        freqs = {}
        for val in nums:
            freqs[val] = freqs.get(val, 0) + 1
        
        # Factors of all composites with no dupcliate factors
        factors = {6: [2, 3], 10: [2,5], 14: [2,7], 15: [3, 5], 21: [3, 7], 22: [2, 11], 26: [2, 13], 30: [2, 3, 5]}

        # List of primes 
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        
        # List of composites WITH dupcliate factors 
        invalid = [4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28]
        compressed = set(nums)
        
        # Sorted list without invalid numbers
        reduced = sorted([val for val in compressed if val not in invalid])
    
        # If no valid numbers, return 0
        if not reduced:
            return 0
    
        self.total = 0

        if reduced[0] == 1:
            reduced.pop(0)
        
        def traverse(index, used, subtotal):

            # Base Case: traversed through entire list
            if index == len(reduced):
                self.total += subtotal
                self.total %= 1000000007
                return 
            
            # Check if factors have already been used 
            valid = True 
            number = reduced[index]
            if number in factors.keys():
                for factor in factors[number]:
                    if factor in used:
                        valid = False 
                        break 
            else:
                if number in used:
                    valid = False 
            
            # Always trigger the skip call 
            traverse(index + 1, used[:], subtotal)

            # If none of the factors have been used, add them to the used list and call another traversal
            if valid:
                if number in factors.keys():
                    for factor in factors[number]:
                        used.append(factor) 
                else:
                    used.append(number)
                
                # The idea here is we can select EXACTLY 1 copy of this number, so multiply to find the number of viable combinations up to this point
                subtotal *= freqs[number]
                subtotal %= 1000000007

                traverse(index + 1, used[:], subtotal)
            
        traverse(0, [], 1)
        
        # Account for the 1's in the original list 
        if 1 in freqs.keys():
            return ((self.total - 1) * pow(2, freqs[1]) + (pow(2, freqs[1]) - 1)) % 1000000007
        
        return (self.total - 1) % 1000000007