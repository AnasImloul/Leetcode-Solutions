# Runtime: 111 ms (Top 25.49%) | Memory: 14.1 MB (Top 45.43%)
class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        max_dur = releaseTimes[0]
        max_key = keysPressed[0]

        for i in range(1, len(releaseTimes)):
            if releaseTimes[i] - releaseTimes[i-1] > max_dur:
                max_dur = releaseTimes[i] - releaseTimes[i-1]
                max_key = keysPressed[i]
            elif releaseTimes[i] - releaseTimes[i-1] == max_dur and max_key < keysPressed[i]:
                 max_key = keysPressed[i]

        return max_key