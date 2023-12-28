// Runtime: 42 ms (Top 73.46%) | Memory: 17.40 MB (Top 13.95%)

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
		# initialise a dictionary since we're going to want to count the occurences of each element in arr1
        dic = {}
		# this loop populates the dictionary with the number of occurences for each element
        for elem in arr1:
            if dic.get(elem) is None:
                dic[elem] = 1
            else:
                dic[elem] = dic[elem] + 1
		# initialise a new list to store the values which exist in both arr2 and arr1
        output = []
		# populate output with the elements multiplied by their occurences (e.g. [1]*2 = [1, 1])
        for elem in arr2:
            output += [elem]*dic[elem]
		# initialise a new list to store the elements which are in arr1 but not arr2
        extra_output = []
		# populate extra_output with these elements multiplied by their occurences. 
		# Note: set(arr1)-set(arr2) provides us with the set of numbers which exist in arr1 but not in arr2
        for elem in set(arr1)-set(arr2):
            extra_output += [elem]*dic[elem]
		# return the first list and the sorted second list
        return output + sorted(extra_output)
