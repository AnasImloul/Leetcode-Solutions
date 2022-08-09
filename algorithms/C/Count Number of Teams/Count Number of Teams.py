class Solution:
    def numTeams(self, ratings: List[int]) -> int:
        upper_dps = [0 for _ in range(len(ratings))]
        lower_dps = [0 for _ in range(len(ratings))]
        
        count = 0
        for i in range(len(ratings)):
            for j in range(i):
                if ratings[j] < ratings[i]:
                    count += upper_dps[j]
                    upper_dps[i] += 1
                else:
                    count += lower_dps[j]
                    lower_dps[i] += 1
                    
        return count
