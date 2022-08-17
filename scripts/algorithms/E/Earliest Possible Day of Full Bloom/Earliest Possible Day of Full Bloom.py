class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        data = list(zip(plantTime, growTime))
        data.sort(key=lambda x: -x[1]) #sort by grow time in descending order
        
        res = 0
        start_time = 0
        for plant, grow in data:
            start_time += plant
            res = max(res, start_time + grow)
        return res
