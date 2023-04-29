class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        memo = {}


        def can_construct(target, strings_bank, memo):    
            if target in memo:
                return memo[target]
            if target == "":
                return True
            for element in strings_bank: # for every element in our dict we check if we can start constructing the string "s"
                if element == target[0:len(element)]: # the remaining of the string "s" (which is the suffix) is the new target 
                    suffix = target[len(element):]
                    if can_construct(suffix, strings_bank, memo):
                        memo[target] = True
                        return True
            memo[target] = False
            return False


        return can_construct(s, wordDict, memo)