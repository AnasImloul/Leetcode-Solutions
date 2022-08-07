from collections import defaultdict

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        
        
        
        # ll=res
        # k=0
        # ind=0
        # kmk=1
        jj=None
        g=defaultdict(lambda:-1)
        k=0
        hh=head
        while(head):
            res=Node(head.val)
            if k==0:
                jj=res

            if k==1:
                prev.next=res
            
            g[head]=res
            prev=res
            k=1
            head=head.next
            
        # print(g)
        
        # for i in g:
        #     print(i.val,g[i].val)
            
        kk=jj
        mm=jj
        # print(head)
        while(hh):
            if hh.random!=None:
                
                jj.random=g[hh.random]
            else:
                jj.random=None
            hh=hh.next
            
            jj=jj.next    
            # head=head.next
        kkk=kk
        # while(kk):
        #     print(kk.val)
        #     kk=kk.next
            
        return kkk
#             if g[ind]!=-1:
#                 g[ind].random=res
                
#             res=Node(head.val)
#             if kmk==1:
#                 ll=res
#             kmk=0
#             mm=head.next
#             if mm:
                
#                 jk=Node(mm.val)
#                 res.next=jk
#             if head.random !=None:
#                 g[head.random]=res
#             else:
#                 res.random=None
#             head=head.next
#             ind+=1
#             # res=res.next
            
#         return ll
            
            # if k==0:
            #     res.val=head.val
            #     mm=head.next
                
                
                
            
            
