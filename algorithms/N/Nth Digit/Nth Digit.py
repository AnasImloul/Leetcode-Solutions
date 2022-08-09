class Solution:
    def findNthDigit(self, n: int) -> int:
        low, high = 1, 0
        place = 1
        
        sum_ = 0
        
        while True:
            high = 10**place -1
            digits_sum = (high - low +1 ) * place
            
            if sum_<= n <= digits_sum + sum_:
                break
            else:
                low = high+1
                sum_+= digits_sum
            place += 1
        
        remaining_digits = n - sum_
        
        position = (remaining_digits-1)//place 
        index_ =  remaining_digits - position*place -1
        
        
        number = low + position
        # return str(number)[index_]
        count = 0
        index_ = place - 1 - index_
        l = []
        # 
        while number:
            if count == index_:
                return number%10
            number = number//10
            count+=1

