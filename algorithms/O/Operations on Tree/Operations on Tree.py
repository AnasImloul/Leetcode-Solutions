class LockingTree:

    def __init__(self, parent: List[int]):
        self.p = collections.defaultdict(lambda: -2)
        self.c = collections.defaultdict(list)
        for i, p in enumerate(parent):
            self.c[p].append(i)
            self.p[i] = p
        self.user = collections.defaultdict(set)
        self.node = collections.defaultdict(lambda: -2)

    def lock(self, num: int, user: int) -> bool:
        if self.node[num] == -2:
            self.user[user].add(num)
            self.node[num] = user
            return True
        return False 

    def unlock(self, num: int, user: int) -> bool:
        if self.node[num] == user: 
            del self.node[num]
            self.user[user].remove(num)
            return True
        return False        

    def upgrade(self, num: int, user: int) -> bool:
        if self.node[num] != -2: return False
        if not self.has_locked_descendant(num): return False
        if self.has_locked_ancester(num): return False
        self.lock(num, user)
        self.unlock_descendant(num)
        return True
    
    def has_locked_descendant(self, num):  #function to check if alteast one desendent is lock or not 
        has = False
        for child in self.c[num]:
            if self.node[child] != -2:
                return True
            has |= self.has_locked_descendant(child)
        return has               
        
    def has_locked_ancester(self, num):   # function to check if no parent is locked 
        if num == -1: return False
        if self.node[self.p[num]] != -2:
            return True
        return self.has_locked_ancester(self.p[num])

    def unlock_descendant(self, num):   # function fro unlocking all desendents 
        for child in self.c[num]:
            if child in self.node:
                user = self.node[child]
                del self.node[child]
                if user in self.user:
                    self.user[user].remove(child)
            self.unlock_descendant(child)
