# Runtime: 165 ms (Top 59.60%) | Memory: 84.00 MB (Top 12.00%)

class Solution:
    def closestNodes(self, root: TreeNode, queries: List[int]) -> List[List[int]]:

                                                                #    Ex:   queries = [16,2,1,5]
        d, ans = [], []                                         #   
                                                                #            __6__
        def dfs(node):                                          #           /     \
            if not node: return                                 #          3       13___
                                                                #         / \     /     \
            dfs(node.left )                                     #        2   4   9      _15
            d.append(node.val)                                  #                     /
            dfs(node.right)                                     #                    14


        dfs(root)                                               #   d = [2, 3, 4, 6, 9,13,14,15]
                                                                #  idx:  0  1  2  3  4  5  6  7 
        for q in queries:                                       #
            idx = bisect_left(d,q)                              #     q    idx    ans
                                                                #    –––   –––    –––
            if idx == len(d): ans.append([d[-1]   ,-1    ])     #    16     8    [15,-1]  <--  idx == 8
            elif d[idx] == q: ans.append([d[idx]  ,d[idx]])     #     2     0    [ 2, 2]  <-- d[0] == 2
            elif    idx == 0: ans.append([-1      ,d[0]  ])     #     1     0    [-1, 2]  <--  idx == 0
            else            : ans.append([d[idx-1],d[idx]])     #     5     3    [ 4, 6]  <-- else [d[2],d[3]] 

        return ans                                              #  return [[15,-1],[2,2],[-1,2],[4,6]]
