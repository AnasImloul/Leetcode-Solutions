class Node(object):
    def __init__(self, nodeId, visitedSoFar):
        self.id = nodeId
        self.journal = visitedSoFar
    
    def __eq__(self, other):
        return self.id == other.id and self.journal == other.journal

    def __repr__(self):
        return "Node({}, {})".format(self.id, bin(self.journal)[2:])
    
    def __hash__(self):
        return hash((self.id, self.journal))
    
    
class Solution(object):
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        N = len(graph)
        # 1<<i represents nodes visitedSoFar to reach this node
        # when initializing, we don't know the best node to start 
        # our journey around the world with. So we add all
        # nodes to our queue aka travel journal !
        q = collections.deque(Node(i, 1<<i) for i in range(N))
        distanceToThisNode = collections.defaultdict(lambda :N*N)
        for i in range(N): 
            distanceToThisNode[Node(i, 1<<i)] = 0
        
        endJournal = (1 << N) - 1
        # when we have visited all nodes, this is how our journal 
        # aka visitedSoFar at that node would look like.
        
        while(q):
            node = q.popleft()
            
            dist = distanceToThisNode[node]
            
            if(node.journal == endJournal):
                return dist 
            
            neighbouring_cities = graph[node.id]
            
            for city in neighbouring_cities:
                newJournal = node.journal | (1 << city)
                # doing an OR operation with 1<<city essentially adds
                # this city to the journal. aka sets that nodeId to 1
                
                neighbour_node = Node(city, newJournal)
                    
                if dist+1 < distanceToThisNode[neighbour_node]:
                    distanceToThisNode[neighbour_node] = dist+1
                    q.append(neighbour_node)
        return -1
        
        