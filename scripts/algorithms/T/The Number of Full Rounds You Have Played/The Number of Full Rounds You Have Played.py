# Runtime: 41 ms (Top 45.3%) | Memory: 16.25 MB (Top 71.7%)

class Solution:
    def numberOfRounds(self, startTime: str, finishTime: str) -> int:
        hs, ms = (int(x) for x in startTime.split(":"))
        ts = 60 * hs + ms
        hf, mf = (int(x) for x in finishTime.split(":"))
        tf = 60 * hf + mf
        if 0 <= tf - ts < 15: return 0 # edge case 
        return tf//15 - (ts+14)//15 + (ts>tf)*96