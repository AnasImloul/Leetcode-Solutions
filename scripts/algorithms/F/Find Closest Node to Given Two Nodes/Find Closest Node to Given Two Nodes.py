# Runtime: 3032 ms (Top 5.02%) | Memory: 139.1 MB (Top 14.52%)
class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:

        res = float("inf")

        def dfs(node, arr, counter=0):

            #making sure we haven't visited the node before (i.e., value in the array != -1)
            while arr[node]==-1 and node!=-1:

                #assigning how many moves it takes to reach node
                arr[node] = counter
                next_node = edges[node]

                #going through each neighbor if exists and updating the counter
                dfs(edges[node], arr, counter+1)

            return arr

        #find moves to reach nodes from node1
        n1 = [-1 for i in range(len(edges))]
        dfs(node1, n1)

        #find moves to reach nodes from node2
        n2 = [-1 for i in range(len(edges))]
        dfs(node2, n2)

        answer = -1

        for i in range(len(edges)):

            #check if the end node is reachable from both starting nodes
            if n1[i]!=-1 and n2[i]!=-1:
                maximum_distance = max(n1[i], n2[i])

                #update the distance and the final answer if relevant
                if maximum_distance<res:
                    res = maximum_distance
                    answer = i

        return answer
