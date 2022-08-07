class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        mapping = {"2": "abc",
                   "3": "def",
                   "4": "ghi",
                   "5": "jkl",
                   "6": "mno",
                   "7": "pqrs",
                   "8": "tuv",
                   "9": "wxyz"}
        
        ans = []
        first = True
        for i in range(len(digits)):
            
            # mult: times we should print each digit
            mult = 1 
            for j in range(i+1, len(digits)):
                mult *= len(mapping[digits[j]])
            
            # cycles: times we should run same filling cycle
            if not first:
                cycles = len(ans) // mult
            else:
                cycles = 1
            if times > 1:
                cycles //= len(mapping[digits[i]])
            
            # cyclically adding each digits to answer
            answer_ind = 0 
            for _ in range(cycles):
                for char in mapping[digits[i]]:
                    for __ in range(mult):
                        if first:
                            ans.append(char)
                        else:
                            ans[answer_ind] += char
                        answer_ind += 1
            if first:
                first = False
            
        return ans
