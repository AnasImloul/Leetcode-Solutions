# Runtime: 784 ms (Top 40.9%) | Memory: 50.79 MB (Top 42.2%)

class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        tot = 0 # initialise total
        Head = head
        while Head: # count total nodes
            Head = Head.next # move forward
            tot += 1 # incerse count by one for each node
        one, two = None, None # two pointers of one and two
        count = 1 # we're initialising to one because we have one based index for swapping
        Head = head # regain original head to traverse
        while Head:
            if one and two: break # if we have both one and two then break loop to save time
            if count == k: # if from forward we reach at node k then it's our first node
                one = Head
            if count == (tot-k+1): # if from backward we reach to node k then save it
                two = Head
            Head = Head.next # move further
            count += 1 # increse count
        one.val, two.val = two.val, one.val # now swap values
        return head # return head