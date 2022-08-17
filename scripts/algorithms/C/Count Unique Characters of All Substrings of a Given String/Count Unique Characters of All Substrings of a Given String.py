class Solution:
    def uniqueLetterString(self, s: str) -> int:
        ans = 0
        idx_recorder = collections.defaultdict(list)
        n = len(s)
        
        # record the index for every character
        # s = "ABCA"
        # {
        #     "A": [0, 3],
        #     "B": [1],
        #     "C": [2],
        # }
        for idx in range(len(s)):
            c = s[idx]
            idx_recorder[c].append(idx)
        
        
        def helper(idxes):
            ans = 0

            for i in range(len(idxes)):
                # Count the number of substring which contain the character without duplicating
                # get the left, right value to compute the result.
                # 
                # Take the middle A (idx=3) as example
                # s = 'AxxAxxxAxx'
                #         -
                # left = 3 - 0 = 3 
                # right = 7 - 3 = 4
                #
                # The number of substring which contain this A (idx=3) without containing
                # other A is 3 * 4 = 12
                
                if i == 0:
                    # If it is a first one: it means that there is
                    # no duplicate character in left
                    left = idxes[i] + 1
                else:
                    left = idxes[i] - idxes[i-1]
                
                if i == len(idxes) - 1:
                    # If it is a last one: it means that there is
                    # no duplicate character in right side
                    right = n - idxes[i]
                else:
                    right = idxes[i+1] - idxes[i]
                
                ans += left * right
                
            return ans
        
        ans = 0
        for c in idx_recorder:
            ans += helper(idx_recorder[c])
        return ans
