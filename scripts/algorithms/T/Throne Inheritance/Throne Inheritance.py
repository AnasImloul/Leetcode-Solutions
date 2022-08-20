# Runtime: 1338 ms (Top 35.29%) | Memory: 68.8 MB (Top 82.35%)

class ThroneInheritance:

    def __init__(self, kingName: str):
        # Taking kingName as root
        self.root = kingName

        # notDead will hold all the people who are alive and their level number
        self.alive = {}
        self.alive[kingName] = 0

        # hold edges existing in our graph
        self.edges = {self.root:[]}

    def birth(self, parentName: str, childName: str) -> None:
        # birth --> new child so update alive
        self.alive[childName] = self.alive[parentName]+1

        # add parent to child edges in the edges dictionary
        if parentName in self.edges:
            self.edges[parentName].append(childName)
            if childName not in self.edges:
                self.edges[childName] = []
        else:
            if childName not in self.edges:
                self.edges[childName] = []
            self.edges[parentName] = [childName]

    def death(self, name: str) -> None:
        # removing the dead people from alive map
        del self.alive[name]

    def getInheritanceOrder(self) -> List[str]:

        hierarchy = []
        def dfs(cur,parent=-1):
            nonlocal hierarchy

            # current person available in alive then only add in hierarchy
            if cur in self.alive:
                hierarchy.append(cur)

            # traverse all the children of current node
            for i in self.edges[cur]:
                if i!=parent:
                    dfs(i,cur)
        dfs(self.root)
        return hierarchy