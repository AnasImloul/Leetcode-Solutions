# Time Complexity: O(N) where N is the number of nodes in the tree
# Space Complexity: O(M): where M is the maximum number in the tree at any level
class Solution:
    # The idea is to use BFS, which is a common way to traverse the tree level by level
    # For a standard BFS, we can use queue to push the first root node into a queue
    # Then remove the front of the queue, add its children to back of the queue
    # Do the above steps until the queue is empty
    # In this question, we need to extra thing which is to push the each value of the nodes level by level
    # We can simply use level to store the values of the nodes at current level, 
    # and add it back to ans once we've processed all nodes at that level
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        # the total number of nodes is between [0, 10 ^ 4]
        # check if root is None to cover 0 node case
        if not root: return []
        # init ans
        ans = []
        # standard bfs approach
        # start with the root node
        q = deque([root])
        # do the following logic when the queue is not empty
        while q:
            # level is used to store all the node values at the current level
            level = []
            # for each element in the current queue
            for _ in range(len(q)):
                # get the first node from the queue and pop it
                node = q.popleft()
                # add it to level
                level += [node.val]
                # this node may include other nodes, we add them all to the queue
                for n in node.children: q.append(n)
            # we've processed this level, add it to ans
            ans += [level]
        # return final ans
        return ans