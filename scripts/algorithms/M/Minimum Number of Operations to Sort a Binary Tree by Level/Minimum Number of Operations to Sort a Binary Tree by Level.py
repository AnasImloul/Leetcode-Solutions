# Runtime: 160 ms (Top 30.99%) | Memory: 56.50 MB (Top 34.30%)

class Solution:                                                             # Ex:  root = [1, 4,3, 7,6,8,5, None,None,11,None,9,None,10,None]
    def minimumOperations(self, root: TreeNode) -> int:                     #           _____1____
                                                                            #          /          \
        ans, queue, level = 0, [root],[]                                    #         4___         3___
                                                                            #        /    \       /    \
        while queue :                                                       #       7     _6     8     _5
                                                                            #            /      /     /
            for node in queue:                                              #           11     9     10
                    if node:  level.extend([node.left, node.right])         #
                                                                            #  level         idx             ans
            arr = [(v,i) for i,v in enumerate([c.val for c in level if c])] #  –––––        –––––           –––––
            idx = [i for _,i in sorted(arr)]                                #  [4,3]        [1,0]             1
                                                                            #  [7,6,8,5]    [2,1,3,0]         2
            for i in range(len(idx)):                                       #  [11,9,10]    [1,2,0]           2
                while (idx[i] != i):                                        #                               –––––
                    j = idx[i]                                              #                                 5   <--- ans
                    idx[i], idx[j] = idx[j], idx[i]
                    ans += 1

            queue, level = level, []

        return ans
