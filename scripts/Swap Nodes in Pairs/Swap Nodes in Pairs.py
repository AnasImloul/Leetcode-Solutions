		* 	We can not use head to go through the list because we have to always have the control of the previous node of head, also I think the question does not allow us to move the head
		* 	We create two dummy nodes, one is for going through the whole list and the other one is for taking control of the previous node of head
		* 	After we have those set up, it's similar to reverse a linked list in the iterative way
class Solution:
	def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
		# generate two references, dummy1 is for going through the list, dummy0 is for taking control of the head
		dummy0 = dummy1 = ListNode
		dummy1.next = head
		while (dummy1.next is not None and dummy1.next.next is not None):
			# set the postions for slow and fast, the first and second nodes for all nodes left to be changed 
			slow = dummy1.next
			fast = slow.next
			
			# set up the connection with fast
			dummy1.next = fast
			# set up the connection between the first element and thrid element
			slow.next = fast.next
			# connect second element with the first element			
			fast.next = slow						
			# now we have dummy1.next = the second element, the second element.next = the first element, the first element.next = the thrid element
			# set the dummy1 to slow, which is the previous node for all the left node to be changed, similar to what we set for head at the begnning
			
			dummy1 = slow
			
			# we can only return dummy0.next, because dummy1 node has already passed to the end of the list
		return dummy0.next