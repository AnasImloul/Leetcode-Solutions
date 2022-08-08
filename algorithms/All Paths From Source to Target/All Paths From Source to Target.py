class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        res = []
        self.explore(graph, graph[0], [0], res)
        return res
    
    def explore(self, graph, candidates, step, res):
        if step[-1] == len(graph)-1:
            res.append(list(step))
        else:
            for i in range(len(candidates)):
                step.append(candidates[i])
                self.explore(graph, graph[candidates[i]], step, res)
                step.pop()
