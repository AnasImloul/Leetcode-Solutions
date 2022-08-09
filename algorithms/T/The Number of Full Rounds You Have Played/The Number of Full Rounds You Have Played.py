class Solution:
    def numberOfRounds(self, startTime: str, finishTime: str) -> int:
        sh, sm = startTime.split(":")
        eh, em = finishTime.split(":")
		
        # sh - hour part of the start time
		# sm - minute part of the start time
		# eh - hour part of the finish time
		# em = minute part of the finish time
        sh, sm, eh, em = int(sh), int(sm), int(eh), int(em)
        
        if sh == eh:
            if sm <= em:
                return em//15 - (sm//15 + 1)
            else:
                val = 0
                sm = 60 - sm
                val += sm//15
                val += em//15
                return 23*4 + val 
        else:
            if eh < sh:
                eh += 24
            val = 0
            sm = 60 - sm
            val += sm//15
            val += em//15
            sh += 1
            return (eh-sh)*4 + val
