class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        critical_conn = []
        visited = [0]*n
        arrival_time = [0]*n
        min_time = [0]*n
        adj = [[] for i in range(n)]
        for i in range(len(connections)):
            adj[connections[i][0]].append(connections[i][1])
            adj[connections[i][1]].append(connections[i][0])
        
        def recur(node, parent, timer):
            visited[node] = 1
            arrival_time[node] = timer + 1
            min_time[node] = timer + 1
            timer += 1
            
            for it in adj[node]:
                if it != parent: ''' because we have to eventually check whether
				the edge between "it" and "node" is a critical edge or not,
				i.e. we need to check whether the node can be visited through
				any path other than the path via the parent.
				So we skip when it == parent. Otherwise we'll not be able to differentiate.'''
                    if visited[it] == 0:
                        recur(it, node, timer)
                        min_time[node] = min(min_time[node], min_time[it])
                        if min_time[it] > arrival_time[node]:
                            critical_conn.append([it, node])
                    else:
                        # min_time[node] = min(min_time[node], arrival_time[it])
                        min_time[node] = min(min_time[node], min_time[it])
						''' the arrival time of a previously visited adjacent node
						would be definitely lesser than the arrival time
						or even the minimum time of the current node.'''

        recur(0, -1, 0)
        print(arrival_time)
        print(min_time)
        return critical_conn
