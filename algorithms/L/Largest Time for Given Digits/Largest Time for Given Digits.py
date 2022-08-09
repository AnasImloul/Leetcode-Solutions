class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        res = ""
        digit_freq = collections.Counter(arr)
        # first digit
        
        
        if 2 in arr and sum([digit_freq[d] for d in range(6)]) > 2:
            res += "2"
            arr.remove(2)
        else:
            for digit in [1,0]:
                if digit in arr:
                    res += str(digit)
                    arr.remove(digit)
                    break
        # can't make 24-hour time
        if len(res) == 0:
            return ""
        
        # second digit 0-3
        if res == "2":
            for digit in [3,2,1,0]:
                if digit in arr:
                    res += str(digit)
                    arr.remove(digit)
                    break
            # no 0-3 left in arr
            if len(res) == 1:
                return ""
        # second digit 0-9
        else:
            for digit in range(9,-1,-1):
                if digit in arr:
                    res += str(digit)
                    arr.remove(digit)
                    break
        
        res += ":"
        
        for digit in range(5, -1, -1):
            if digit in arr:
                res += str(digit)
                arr.remove(digit)
                break
            
        if len(res) == 3:
            return ""
        
        for digit in range(9,-1,-1):
            if digit in arr:
                res += str(digit)
                return res
                
