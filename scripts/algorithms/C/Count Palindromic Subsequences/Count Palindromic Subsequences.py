// Runtime: 457 ms (Top 74.59%) | Memory: 115.80 MB (Top 6.83%)

class Solution:
    def countPalindromes(self, S: str) -> int:
        #Ignore string less than 5 characters (cannot have a 5 length substring)
        if len(S) < 5:
            return 0
        
        #Returns the running pair counts for each index
        def get_pairs(s):
            seen_cnt = {str(num):0 for num in range(10)}
            seen_cnt[s[0]] = 1 #We have seen the first character since we start the loop at 1
            pair_cnts = defaultdict(int)
            res = [None] #Filler empty dict (index = 0 / end index)
            
            #Getting running pairs
            for idx in range(1, len(s) - 1):
                res.append(pair_cnts.copy()) #Append running pair counts
                for num in seen_cnt.keys():
                    pair_cnts[(num, s[idx])] += seen_cnt[num]
                seen_cnt[s[idx]] += 1
                
            #Filler empty dict (index = 0 / end index)
            res.append(None)
            
            return res
        
        res = 0
        #Getting post and pre pair counts
        pre, post = get_pairs(S), get_pairs(S[::-1])[::-1]
        
        #Check all possible middle characters -> S[2, len(S) - 2)
        for idx in range(2, len(S) - 2):
            for key, val in pre[idx].items():
                if key in post[idx]:
                    res += post[idx][key] * val #Total pairs per key
                    res %= 1000000007
                    
        return res             
