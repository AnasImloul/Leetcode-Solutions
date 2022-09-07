# Runtime: 64 ms (Top 18.00%) | Memory: 13.8 MB (Top 71.33%)
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        result = [label]

        #determine level of label
        #O(log n)
        level, nodeCount = 1, 1
        while label >= nodeCount * 2:
            nodeCount *= 2
            level += 1

        #Olog(n) time
        while label > 1:
            #compute max and min node
            maxNode, minNode = 2**level-1, 2**(level-1)

            parent = ((maxNode + minNode) - label) // 2

            #slightly costly operation
            result = [parent] + result

            label = parent
            level -= 1

        return result