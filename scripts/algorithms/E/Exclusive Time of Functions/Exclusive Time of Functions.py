# Runtime: 78 ms (Top 92.98%) | Memory: 14.2 MB (Top 33.69%)
class Solution:
    #T=O(n), S=O(d)
    #n=len of logs, d=depth of stack
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        #init result array to zeroes of length n (function ids)
        res = [0]*n
        stack = []
        #iterate through logs
        for log in logs:
            #split the log
            #function_id: start|end: timestamp
            log = log.split(":")
            #type cast function id and timestamp to int type
            id = int(log[0])
            timestamp = int(log[2])
            state = log[1]
            #detect start of a function call
            #stack[function_id, start_timestamp]
            if state == "start":
                #stack is non empty
                if stack:
                    #get the time taken by last function so far
                    res[stack[-1][0]] += timestamp - stack[-1][1]
                #append the current function_id and start timestamp to the stack
                stack.append([id, timestamp])
            else:
                #get the time consumed by current function
                #dont forget to add 1 as the last unit of time should be included
                res[id] += timestamp - stack.pop()[1] + 1
                if stack:
                    #update the start time of last function in stack to get the cumulative result
                    stack[-1][1] = timestamp + 1

        return res