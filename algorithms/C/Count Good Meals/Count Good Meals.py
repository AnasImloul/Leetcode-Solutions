class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        pows = [2 ** i for i in range(0,22)] # form our list of powers of 2
        dp_seen = {} # dict to store what we've seen - dynamic programming solution for time requirement
        count = 0 # to store the answer

        for j in range(0, len(deliciousness)):
            for i in range(0, len(pows)):
                if pows[i] - deliciousness[j] in dp_seen: # "if we find a previous deliciousness[j] as pows[i] - deliciousness[j], then we will add dp_seen[deliciousness[j]] to count"
                    count += dp_seen[pows[i] - deliciousness[j]]
            if deliciousness[j] in dp_seen:
                dp_seen[deliciousness[j]] += 1 
            else:
                dp_seen[deliciousness[j]] = 1
                
        return count % (10**9 + 7) # the arbitrary modulo, presumably to reduce the answer size
		```