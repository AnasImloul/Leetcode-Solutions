MAX=2**31
def consume_tail(current, s):
    # Following the definition of the fibonacci sequence
    # we know that the sum of the last two values in our 
    # `current` list determines the next value in the sequence.
    # So that value, our "target", is what we're looking for next in
    # `s`.
    target = current[-1] + current[-2]
    
    if target > MAX:
        return False
    
    sTarget = str(target) 
    # If the next value in the fibonacci sequence
    # is found at the beginning of s
    # we can continue to process the remaining 
    # portion of the string.
    if s.find(sTarget) == 0:
        current.append(target)
    else:
        return False
    
    if sTarget != s:
        return consume_tail(current, s[len(sTarget):])
    
    return current
        

class Solution:    
    def splitIntoFibonacci(self, num: str) -> List[int]:
        
        # Identify candidate for the first
        # number in fibonacci sequence
        for i in range(len(num)):
            if num[0] == "0" and i > 0:
                break
                
            first = num[0:i+1]
            
            # If our current candidate for the first number
            # of the sequence is already larger that our 
            # maximum value in the spec, don't bother doing anymore work.
            if int(first) > MAX:
                return []
            
            tail = num[i+1:]
            
            # Identify candidate for the scond
            # number in fibonacci sequence
            for j in range(len(tail)):
                if tail[0] == "0" and j > 0:
                    break
                    
                second = tail[0:j+1]
                if int(second) > MAX:
                    break
                
                # With our current candidates (first and second),
                # we can consume the remaining portion of the string (tail[j+1:])
                # to determine if it contains the correct values for a fibonacci sequence
                # beginning with [first, second]
                result = consume_tail([int(first), int(second)], tail[j+1:])
                if result:
                    return result
        return []
