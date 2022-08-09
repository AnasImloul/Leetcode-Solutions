from collections import defaultdict
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        self.d=defaultdict(list)
        def check(root,ind):
            self.d[ind].append(root.val)
            if root.children:
                for x in root.children:
                    check(x,ind+1)
        if root==None:
            return []
        check(root,0)
        l=[]
        for x in sorted(self.d.keys()):
            l.append(self.d[x])
        return l
