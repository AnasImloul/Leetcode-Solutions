class Node:
    def __init__(self):
        self.children = defaultdict(Node)
        self.hash = ''
        self.deleted = False
    
    def add(self, path, i=0):
        if i != len(path):
            self.children[path[i]].add(path, i + 1)
            
    def calc_hash(self, hashes, name='root'):
        for child_name, child in sorted(self.children.items()):
            self.hash += f'{child.calc_hash(hashes, child_name)}+'
        if self.hash:
            hashes[self.hash].append(self)
        return f'{name}({self.hash})'
    
    def to_list(self, lst, path=[]):
        for name, node in self.children.items():
            if not node.deleted:
                lst.append(path + [name])
                node.to_list(lst, path + [name])

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = Node()
        for path in paths:
            root.add(path)
        hash_to_nodes = defaultdict(list)
        root.calc_hash(hash_to_nodes)
        for nodes in hash_to_nodes.values():
            if len(nodes) > 1:
                for node in nodes:
                    node.deleted = True
        res = []
        root.to_list(res)
        return res
