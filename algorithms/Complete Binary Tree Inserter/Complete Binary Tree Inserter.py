class CBTInserter:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.queue = Queue()
        self.queue.put(self.root)
        self.parent_of_last_inserted = None
        
    def insert(self, val: int) -> int:
        if self.parent_of_last_inserted is not None and self.parent_of_last_inserted.right is None:
            self.parent_of_last_inserted.right = TreeNode(val)
            self.queue.put(self.parent_of_last_inserted.right)
            return self.parent_of_last_inserted.val
        
        while not self.queue.empty():
            node = self.queue.get()
            if node.left is None:
                node.left = TreeNode(val)
                self.queue.put(node.left)
                self.parent_of_last_inserted = node
                return node.val
            else:
                self.queue.put(node.left)
            if node.right is None:
                node.right = TreeNode(val)
                self.queue.put(node.right)
                self.parent_of_last_inserted = node
                return node.val
            else:
                self.queue.put(node.right)
        

    def get_root(self) -> Optional[TreeNode]:
        return self.root
