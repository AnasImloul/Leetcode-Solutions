class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        hmap, res = defaultdict(int), []
        for num in digits:
            hmap[num] += 1   #counting frequency of digits of digits array
        
        for num in range(100, 999, 2):  #step 2 because we need even numbers
            checker = defaultdict(int)
            for digit in str(num):
                checker[int(digit)] += 1    #counting frequency of digits of num
            
			#check if every digit in num is in digits array and its frequency is less than or equal to its frequency in digits array
            if all(map(lambda x: x in hmap and checker[x] <= hmap[x], checker)):
                res.append(num)
        
        return res
