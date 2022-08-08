class Solution:
    def average(self, salary: List[int]) -> float:       

        return (sum(salary)-min(salary)-max(salary))/(len(salary)-2)
