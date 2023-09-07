# Runtime: 1647 ms (Top 68.5%) | Memory: 108.91 MB (Top 50.2%)

class Solution(object):
    def validPath(self, n, edges, start, end):
        """
        :type n: int
        :type edges: List[List[int]]
        :type start: int
        :type end: int
        :rtype: bool
        """
        visited = [False]*n
        d = {}
		#store the undirected edges for both vertices
        for i in edges:
            if i[0] in d:
                d[i[0]].append(i[1])
            else:
                d[i[0]] = [i[1]]
                
            if i[1] in d:
                d[i[1]].append(i[0])
            else:
                d[i[1]] = [i[0]]
        #create a queue as we will apply BFS
        q = [start]
        while q:
            curr = q.pop(0)  #pop the first element as we do in queue
            if curr == end:  #if its the end then we can return True
                return True
            elif curr in d and not visited[curr]: #else if it is not the end then check whether its visited or not
                q.extend(d[curr])  #add the adjacent vertices of the current node to the queue
            visited[curr] = True  #mark this curr vertex as visited = True, so that we dont visit this vertex again
        return False  #return False if the queue gets empty and we dont reach the end