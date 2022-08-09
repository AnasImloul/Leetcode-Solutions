class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        
        # Initializing the last index as zero
        last_index = 0
        
        #iterating each number to find the occurences, \
        # and to find if the number is greater than the next element \ 

        for num in range(1, len(number)):
            
            # Handling [case 1] and [case 2]
            if number[num-1] == digit:
                if int(number[num]) > int(number[num-1]):
                    return number[:num-1] + number[num:]
                else:
                    last_index = num - 1
        
        # If digit is the last number (last occurence) in the string [case 3]
        if number[-1] == digit:
            last_index = len(number) - 1

        return number[:last_index] + number[last_index + 1:]
