class Solution:
	def addTwoNumbers(self, l1, l2):
		list1 = make_list_from_ListNode(l1)
		list2 = make_list_from_ListNode(l2)

		### RIGHT PAD WITH ZEROES
		len_list1 = len(list1)
		len_list2 = len(list2)
		if len_list1 > len_list2:
			pad = len_list1 - len_list2
			list2 = list2 + [0,] * pad
		elif len_list2 > len_list1:
			pad = len_list2 - len_list1
			list1 = list1 + [0,] * pad

		### DO THE MATH
		d = 0
		the_sum = list()
		for x,y in zip(list1, list2):
			d, m = divmod(x + y + d, 10)
			the_sum.append(m)
		if d != 0:
			the_sum.append(d)
		return make_ListNode_from_list(the_sum)
