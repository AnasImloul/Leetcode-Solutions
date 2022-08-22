# Runtime: 254 ms (Top 40.58%) | Memory: 15.6 MB (Top 60.31%)
"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def dfs(self, graph, employees, empId, totalImportance, visited):
        totalImportance += graph[empId][0]
        visited.add(empId)

        for neighbour in graph[empId][1]:
            if neighbour not in visited:
                totalImportance = self.dfs(graph, employees, neighbour, totalImportance, visited)

        return totalImportance

    def getImportance(self, employees: List['Employee'], id: int) -> int:
        graph = {}

        for employeeInfo in employees:
            empId, importance, suboordinates = employeeInfo.id, employeeInfo.importance, employeeInfo.subordinates
            graph[empId] = [importance, suboordinates]

        n = len(employees)

        if graph[id][1] == []:
            return graph[id][0]

        visited = set()
        totalImportance = 0
        totalImportance = self.dfs(graph, employees, id, totalImportance, visited)

        return totalImportance