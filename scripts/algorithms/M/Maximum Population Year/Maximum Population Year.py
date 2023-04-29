class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        logs.sort(key=lambda x: x[0])
        print(logs)
        living = 0
        max_living = 0
        year = 0

        for ind, (start, stop) in enumerate(logs):
            born = ind+1
            dead = 0
            for i in range(ind):
                if logs[i][1] <= start:
                    dead += 1
            
            living = born - dead
            # print(born, dead, living, max_living)
            if living > max_living:
                max_living = living
                year = start

        
        
        return year