class Solution:
    def numDecodings(self, s: str) -> int:
        non_zero = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
        first_incl, second_incl = 1, 0
        first_excl, second_excl = 0, 0
        
        if s[0] in non_zero:
            second_incl = 1
        if s[0] == '*':
            second_incl = 9
            
        for i in range(1, len(s)):
            new_incl, new_excl = 0, 0
            if s[i] == '*':
                new_incl = 9 * (second_incl + second_excl)
                
                if s[i-1] == '1':
                    # number is of type (1, *)
                    new_excl = 9 * (first_incl + first_excl)
                    
                elif s[i-1] == '2':
                    # number is of type (2, *)
                    new_excl = 6 * (first_incl + first_excl)
                    
                elif s[i-1] == '*':
                    # number is of type (*, *)
                    new_excl = 15 * (first_incl + first_excl)
            else:
                if s[i] in non_zero:
                    new_incl = second_incl + second_excl
                        
                if s[i-1] == '*':
                    # number is of type (*,digit)
                    if int(s[i]) <= 6:
                        new_excl = 2 * (first_excl + first_incl)
                    else:
                        new_excl = first_incl + first_excl
                        
                else:
                    # number is of type (digit,digit)
                    val = int(s[i-1:i+1])
                    if 10 <= val <= 26:
                        new_excl = first_incl + first_excl
                    else:
                        new_excl = 0
            first_incl, first_excl = second_incl, second_excl
            second_incl, second_excl = new_incl, new_excl
        return (second_incl + second_excl) % (10**9 + 7)
