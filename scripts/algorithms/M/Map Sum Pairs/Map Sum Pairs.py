// Runtime: 29 ms (Top 97.14%) | Memory: 17.50 MB (Top 9.54%)

class MapSum:

    def __init__(self):
        self.trie = {}

    def insert(self, key: str, val: int) -> None:
        node = self.trie
        for ch in key:
            node = node.setdefault(ch, {})
        node['val'] = val
        return

    def sum(self, prefix: str) -> int:
        def traverse(node):
            nonlocal res
            if not node:
                return
            if 'val' in node:
                res += node['val']
            for child in node:
                if child == 'val': continue
                traverse(node[child])
            return
            
        node = self.trie
        for ch in prefix:
            node = node.get(ch, {})
            if not node:
                return 0
        res = 0
        traverse(node)
        return res
