# Runtime: 112 ms (Top 7.97%) | Memory: 14.4 MB (Top 40.85%)
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        self.max_lvl = (0,[])
        self.pathes = {}
        def rec(root,parent,lvl):
            if not root:
                return
            if lvl > self.max_lvl[0]:
                self.max_lvl = (lvl,[root])
            elif lvl == self.max_lvl[0]:
                self.max_lvl = (lvl,self.max_lvl[1]+[root])
            self.pathes[root] = parent
            rec(root.left,root,lvl+1)
            rec(root.right,root,lvl+1)
        rec(root,None,0)
        print(self.max_lvl)
        # for key in self.pathes:
        # if key!=None and self.pathes[key]!=None:
        # print(key.val,"-",self.pathes[key].val)
        if len(self.max_lvl[1]) < 2:
            return self.max_lvl[1][0]
        parent = self.max_lvl[1]
        while len(parent) > 1:
            temp = set()
            for p in parent:
                temp.add(self.pathes.get(p,None))
            parent = temp
        return parent.pop()
