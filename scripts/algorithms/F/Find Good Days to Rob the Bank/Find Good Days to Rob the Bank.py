class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        decreasing = [0] * len(security)
        increasing = [0] * len(security)
        for i in range(len(security)):
            if i > 0 and security[i - 1] >= security[i]:
                decreasing[i] = decreasing[i - 1] + 1
        for i in reversed(range(len(security))):
            if i < len(security) - 1 and security[i] <= security[i + 1]:
                increasing[i] = increasing[i + 1] + 1
        return [i for i in range(len(security)) if increasing[i] >= time and decreasing[i] >= time]