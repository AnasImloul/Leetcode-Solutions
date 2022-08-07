
```class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        
        while len(lists)>1:
            mergedList = []
            for i in range(0,len(lists),2):
                list1 = lists[i]
                list2 = lists[i+1] if i+1 < len(lists) else None
                mergedList.append(self.mergeTwoLists(list1,list2))
            lists = mergedList
        return lists[0]
    
    def mergeTwoLists(self,list1, list2):
        res = ListNode()
        temp = res
        while list1 and list2:
            if list1.val <= list2.val:
                temp.next = list1
                list1 = list1.next
            elif list1.val > list2.val:
                temp.next = list2
                list2 = list2.next
            temp = temp.next
        if list1:
            temp.next = list1
        if list2:
            temp.next = list2
        return res.next``