// Runtime: 31 ms (Top 99.88%) | Memory: 19.20 MB (Top 96.36%)

class Solution:
    def findMode(self, root):
        curr_node = root
        result = []
        curr_streak = 0
        curr_num = float("inf")
        max_streak = 0

        while curr_node:
            if curr_node.left:
                neighbor = curr_node.left
                while neighbor.right is not None:
                    neighbor = neighbor.right
                neighbor.right = curr_node
                
                tmp = curr_node.left
                curr_node.left = None
                curr_node = tmp
            else: 
                # since we deleted the left pointer when we were done processing in the previous if-block, 
                # we know that we only reach this else case 
                # if we've already processed this node. 
                # Therefore, do the value processing here 
                # and move to the right neighbor afterward
                if curr_node.val == curr_num:
                    curr_streak += 1
                else:
                    curr_streak = 0
                    curr_num = curr_node.val
                
                if curr_streak == max_streak:
                    result.append(curr_num)
                elif curr_streak > max_streak:
                    max_streak = curr_streak
                    result = [curr_num]
        
                curr_node = curr_node.right
        
        return result
