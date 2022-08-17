class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        ret = [0] * k  # UAM store
        user_acts = {}  # User minutes store
        
        # Adding user minutes to hash table
		for log in logs:
            if user_acts.get(log[0], 0):
                user_acts[log[0]].append(log[1])
            else:
                user_acts[log[0]] = [log[1]]
                
        # Calculating UAM
		for k, v in user_acts.items():
            l = len(set(v))
            ret[l-1] += 1
    
        return ret
