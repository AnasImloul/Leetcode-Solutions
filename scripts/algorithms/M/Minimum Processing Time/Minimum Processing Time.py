# Runtime: 106 ms (Top 10.29%) | Memory: 33.50 MB (Top 72.03%)

class Solution:
    def minProcessingTime(self, processorTimes, taskTimes):
        processorTimes.sort()
        taskTimes.sort(reverse=True)
        processorIndex = 0
        answer = 0

        for processingTime in processorTimes:
            currentMax = 0
            taskCount = 0

            while processorIndex < len(taskTimes) and taskCount < 4:
                currentMax = max(currentMax, processingTime + taskTimes[processorIndex])
                processorIndex += 1
                taskCount += 1

            answer = max(answer, currentMax)

        return answer
