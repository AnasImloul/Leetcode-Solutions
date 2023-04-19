class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        
        empId, unit, lastLeaveTime = 0, 0, 0

        for id, leaveTime in logs:
            
            div = leaveTime - lastLeaveTime 

            if div > unit:
                empId = id
                unit = div
            
            if div == unit and empId > id:
                empId = id
                unit = div

            lastLeaveTime = leaveTime

        return empId
