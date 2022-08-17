class Solution:
def maximumTime(self, time: str) -> str:
    memo = {"0":"9",
            "1":"9",
            "?":"3", 
            "2":"3"}
    
    answer = ""
    for idx, val in enumerate(time):
        if val == "?":
            if idx == 0:
                if time[idx+1] == "?":
                    answer += "2"
                    
                else:
                    if int(time[idx+1]) >= 4:
                        answer += "1"
                
                    else: answer += "2"
                
            if idx == 1:
                answer += memo[time[idx-1]]
            
            if idx == 3:
                answer += "5"   
                
            if idx == 4:
                answer += "9"
        
        else:
            answer += val
    
    return answer
