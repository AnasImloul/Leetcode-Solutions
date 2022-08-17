class Solution:
def numPairsDivisibleBy60(self, time: List[int]) -> int:
    
    for i,t in enumerate(time):
        time[i] = t%60
        
    
    mp = defaultdict(int)
    ans = 0
    for modtime in time:
        if modtime == 0:
            ans+= mp[modtime]
        else:
            ans+= mp[60-modtime]
        mp[modtime]+=1
    return ans