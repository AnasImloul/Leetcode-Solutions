
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        
        # Function which will take integer number as an input and return it's sum
        # if input is 123 then it'll return 6 (1+2+3)
        
        def numberSum(number:int)->int:
            sum1 = 0
            while number:
                sum1 += number%10
                number = number //10
            return sum1
        
        # create a hashmap having key as box number and value as box count
        hashMap = defaultdict(int)
        
        for i in range(lowLimit, highLimit+1):
            # pass i to numberSum function inorder to find it's sum1
            # Once sum1 is found, we'll use this sum1 as our hash_val
            # If box has alreary one ball avaiable then increment it by one
            hash_val = numberSum(i)
            hashMap[hash_val] += 1
        
        # Check balls in every box
        # hashMap.values() will create an array of balls count in each box.
        values = hashMap.values()
        
        # return maximum balls in boxes
        return max(values)

